package com.carrotgarden.osgi_host;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.ServiceLoader;

import org.apache.pivot.beans.BXMLSerializer;
import org.apache.pivot.wtk.Application;
import org.apache.pivot.wtk.DesktopApplicationContext;
import org.apache.pivot.wtk.Display;
import org.apache.pivot.wtk.Window;
import org.osgi.framework.Bundle;
import org.osgi.framework.BundleContext;
import org.osgi.framework.Constants;
import org.osgi.framework.launch.Framework;
import org.osgi.framework.launch.FrameworkFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.carrotgarden.api.HostService;
import com.carrotgarden.impl.HostServiceImpl;

public class MainPivot implements Application {

	private final static Logger log = LoggerFactory.getLogger(MainPivot.class);

	private Window window;
	private Framework framework;

	/*
	 * http://download.oracle.com/javase/1.5.0/docs/guide/deployment/deployment-
	 * guide/properties.html
	 */
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
		// String export =
		// "com.carrotgarden.api,org.slf4j;version=1.6.1,org.slf4j.impl;version=1.6.1,org.osgi.service.event";
		String export = "com.carrotgarden.api,org.slf4j;version=1.6.1,org.slf4j.impl;version=1.6.1";
		return export;
	}

	private void osgiStartup() throws Exception {

		if (framework != null) {
			System.out.println("### osgi is already up");
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

		framework.init();

		BundleContext context = framework.getBundleContext();

		List<String> urls = new LinkedList<String>(); // /

		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.runtime-0.8.0.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.shell-0.8.0.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.gogo.command-0.8.0.jar");

		// urls.add("http://search.maven.org/remotecontent?filepath=org/ops4j/pax/url/pax-url-aether/1.3.2/pax-url-aether-1.3.2.jar");

		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.configadmin-1.2.8.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.scr-1.6.0.jar");
		urls.add("http://apache.cs.utah.edu//felix/org.apache.felix.eventadmin-1.2.10.jar");

		// urls.add("https://oss.sonatype.org/content/repositories/snapshots/com/carrotgarden/carrot-test-osgi-pivot-core/1.0.0-SNAPSHOT/carrot-test-osgi-pivot-core-1.0.0-20110508.200318-9.jar");
		urls.add("reference:file:../carrot-test-osgi-pivot-core/target/classes");

		// urls.add("http://www.eclipsezone.com/files/jsig/bundles/HelloWorld.jar");

		// //////

		context.registerService(HostService.class.getName(),
				new HostServiceImpl(), null);

		for (String url : urls) {
			context.installBundle(url);
		}

		System.out.println("### osgi start");

		framework.start();

		Bundle[] bundles = context.getBundles();

		for (Bundle bundle : bundles) {
			bundle.start();
		}

		// ServiceReference eventAdminRef = context
		// .getServiceReference(EventAdmin.class.getName());
		// EventAdmin eventAdmin = (EventAdmin)
		// context.getService(eventAdminRef);
		// log.info("eventAdmin: {}", eventAdmin);

	}

	private void osgiShutdown() throws Exception {

		if (framework == null) {
			System.out.println("### osgi is already down");
			return;
		}

		framework.stop();
		framework.waitForStop(0);
		framework = null;

		System.out.println("### osgi stop");

	}

	public static void main(String... args) {

		String[] array = new String[] { MainPivot.class.getName() };

		DesktopApplicationContext.main(array);

	}

	@Override
	public void startup(Display display,
			org.apache.pivot.collections.Map<String, String> properties)
			throws Exception {

		System.gc();

		System.out.println("### pivot startup");

		BXMLSerializer bxmlSerializer = new BXMLSerializer();

		window = (Window) bxmlSerializer.readObject(MainPivot.class,
				"MainPivot.bxml");

		window.open(display);

		osgiStartup();

	}

	@Override
	public boolean shutdown(boolean optional) throws Exception {

		System.out.println("### pivot shutdown");

		osgiShutdown();

		if (window != null) {
			window.close();
			window = null;
		}

		System.gc();

		return false;

	}

	@Override
	public void suspend() throws Exception {
	}

	@Override
	public void resume() throws Exception {
	}

}
