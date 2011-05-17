package com.carrotgarden.impl;

import java.io.BufferedInputStream;
import java.io.InputStream;
import java.net.URL;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.ServiceLoader;

import org.osgi.framework.Bundle;
import org.osgi.framework.BundleContext;
import org.osgi.framework.Constants;
import org.osgi.framework.ServiceReference;
import org.osgi.framework.launch.Framework;
import org.osgi.framework.launch.FrameworkFactory;
import org.osgi.service.startlevel.StartLevel;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.carrotgarden.main.App;
import com.carrotgarden.osgi.feature.FeatureBundle;
import com.carrotgarden.osgi.feature.FeatureCollection;
import com.carrotgarden.osgi.feature.FeatureEntry;
import com.carrotgarden.osgi.feature.jackson.FEATURE;

public abstract class HostOsgiFramework {

	protected static final Logger log = LoggerFactory
			.getLogger(App.class);

	private Framework framework;

	private int startLevel;

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

	private <T> String readTextResource(String resource) throws Exception {

		StringBuffer text = new StringBuffer(1024);

		InputStream stream = getClass().getResourceAsStream(resource);

		BufferedInputStream input = new BufferedInputStream(stream);

		byte[] array = new byte[1024];

		int bytesRead = 0;

		while ((bytesRead = input.read(array)) > -1) {
			text.append(new String(array, 0, bytesRead));
		}

		input.close();

		return text.toString();

	}

	private String getPackagesExport() throws Exception {

		String export = readTextResource("/export-package.txt");

		export = export.replaceAll("\\s", "");

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

		Bundle[] bundlesPresent = context.getBundles();
		for (Bundle bundle : bundlesPresent) {
			log.info("present : {} : {}", bundle, bundle.getState());
			if (bundle.getBundleId() == 0) {
				continue;
			} else {
				bundle.stop();
			}
		}

		log.info("### osgi start");
		framework.start();

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

	private void updateMaximumStartLevel(int startLevel) {
		if (this.startLevel < startLevel) {
			this.startLevel = startLevel;
		}
	}

	protected void osgiActivate(URL featureURL, String featureName)
			throws Exception {

		log.info("### osgi activate");

		FeatureCollection result = FEATURE.decode(featureURL);

		FeatureEntry feature = result.findFeatureByName(featureName);

		Collection<FeatureBundle> featureBundles = feature.getBundles();

		BundleContext context = framework.getBundleContext();

		StartLevel starter = (StartLevel) context.getService(context
				.getServiceReference(StartLevel.class.getName()));

		List<Bundle> frameworkBundles = new LinkedList<Bundle>();

		for (FeatureBundle featureBundle : featureBundles) {

			String location = featureBundle.getLocation();
			int startLevel = featureBundle.getStartLevel();

			log.info("install : {}", location);
			Bundle bundle = context.installBundle(location);

			if (startLevel > 0) {
				updateMaximumStartLevel(startLevel);
				starter.setBundleStartLevel(bundle, startLevel);
			}

			frameworkBundles.add(bundle);

		}

		for (Bundle bundle : frameworkBundles) {
			log.info("startup : {}", bundle);
			bundle.start();
		}

		starter.setStartLevel(this.startLevel);

	}

	protected void osgiDeactivate(URL featureURL, String featureName)
			throws Exception {

		log.info("### osgi deactivate");

		FeatureCollection result = FEATURE.decode(featureURL);

		FeatureEntry feature = result.findFeatureByName(featureName);

		Collection<FeatureBundle> featureBundles = feature.getBundles();

		BundleContext context = framework.getBundleContext();

		Bundle[] frameworkBundles = context.getBundles();

		for (FeatureBundle featureBundle : featureBundles) {

			String location = featureBundle.getLocation();

			for (Bundle bundle : frameworkBundles) {

				if (bundle.getBundleId() == 0) {
					continue;
				}

				if (bundle.getLocation().equalsIgnoreCase(location)) {
					log.info("shutdown : {} : {}", bundle, bundle.getState());
					bundle.stop();
				}

			}

		}

	}

	protected <T> T getFrameworkService(Class<T> klaz) {

		if (framework == null && klaz == null) {
			return null;
		}

		BundleContext context = framework.getBundleContext();

		if (context == null) {
			return null;
		}

		ServiceReference reference = context
				.getServiceReference(klaz.getName());

		if (reference == null) {
			return null;
		}

		@SuppressWarnings("unchecked")
		T service = (T) context.getService(reference);

		return service;

	}

}
