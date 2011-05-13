package com.carrotgarden.impl;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.ServiceLoader;

import org.osgi.framework.Bundle;
import org.osgi.framework.BundleContext;
import org.osgi.framework.Constants;
import org.osgi.framework.launch.Framework;
import org.osgi.framework.launch.FrameworkFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.carrotgarden.osgi_host.MainPivot;

public abstract class HostFramework {

	protected static final Logger log = LoggerFactory
			.getLogger(MainPivot.class);

	private Framework framework;

	private String getStorageLocation() {

		String jnlpDir = System.getProperty("deployment.user.cachedir");

		if (jnlpDir == null) {
			// testing
			return "./target/storage";
		} else {
			// release
			String folder = this.getClass().getPackage().getName();
			return jnlpDir + "/" + folder;
		}

	}

	private String getPackagesExport() {
		String export = "com.carrotgarden.api.host,"
				+ "org.slf4j;version=1.6.1," + "org.slf4j.impl;version=1.6.1,"
				+ "org.apache.pivot.wtk;version=2.1.0,"
				+ "org.apache.pivot.beans;version=2.1.0,";
		return export;
	}

	protected abstract void registerHostServices(BundleContext context)
			throws Exception;

	protected void osgiStartup() throws Exception {

		if (framework != null) {
			System.out.println("### osgi is already started");
			return;
		}

		ServiceLoader<FrameworkFactory> loader = ServiceLoader
				.load(FrameworkFactory.class);

		FrameworkFactory factory = loader.iterator().next();

		Map<String, Object> config = new HashMap<String, Object>();

		config.put(Constants.FRAMEWORK_STORAGE, getStorageLocation());

		config.put(Constants.FRAMEWORK_SYSTEMPACKAGES_EXTRA,
				getPackagesExport());

		framework = factory.newFramework(config);

		log.info("### osgi init");
		framework.init();

		BundleContext context = framework.getBundleContext();

		registerHostServices(context);

		//

		Bundle[] bundlesPast = context.getBundles();
		for (Bundle bundle : bundlesPast) {
			log.info("present : {} : {}", bundle, bundle.getState());
			if (bundle.getBundleId() == 0) {
				continue;
			} else {
				bundle.stop();
			}
		}

		//

		List<String> urls = new LinkedList<String>(); // /

		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.runtime-0.8.0.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.shell-0.8.0.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.command-0.8.0.jar");

		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.configadmin-1.2.8.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.eventadmin-1.2.10.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.scr-1.6.0.jar");

		urls.add("reference:file:../carrot-test-osgi-pivot-core/target/classes");

		List<Bundle> bundlesNext = new LinkedList<Bundle>();

		for (String url : urls) {
			log.info("install : {}", url);
			Bundle bundle = context.installBundle(url);
			bundlesNext.add(bundle);
		}

		log.info("### osgi start");
		framework.start();

		for (Bundle bundle : bundlesNext) {
			log.info("startup : {}", bundle);
			bundle.start();
		}

	}

	protected void osgiShutdown() throws Exception {

		if (framework == null) {
			log.info("### osgi is already stopped");
			return;
		}

		framework.stop();
		framework.waitForStop(0);
		framework = null;

		log.info("### osgi stop");

	}

}

// ServiceReference eventAdminRef = context
// .getServiceReference(EventAdmin.class.getName());
// EventAdmin eventAdmin = (EventAdmin)
// context.getService(eventAdminRef);
// log.info("eventAdmin: {}", eventAdmin);
