package com.carrotgarden.impl;

import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.security.Permission;
import java.security.PermissionCollection;
import java.security.Policy;
import java.security.ProtectionDomain;
import java.util.Collection;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.ServiceLoader;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;
import java.util.jar.Attributes;
import java.util.jar.Manifest;

import org.osgi.framework.Bundle;
import org.osgi.framework.BundleContext;
import org.osgi.framework.Constants;
import org.osgi.framework.ServiceReference;
import org.osgi.framework.ServiceRegistration;
import org.osgi.framework.launch.Framework;
import org.osgi.framework.launch.FrameworkFactory;
import org.osgi.service.startlevel.StartLevel;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.carrotgarden.osgi.feature.FeatureBundle;
import com.carrotgarden.osgi.feature.FeatureEntry;
import com.carrotgarden.osgi.feature.FeatureRepository;
import com.carrotgarden.osgi.feature.jackson.FEATURE;

public abstract class HostOsgiFramework {

	protected final Logger log = LoggerFactory.getLogger(getClass());

	{

		getStorageLocation();

		// getPermissions();

	}

	//

	protected PermissionCollection getPermissions() {

		String policyUrl = System.getProperty("java.security.policy");
		log.debug("policyUrl : {}", policyUrl);

		ProtectionDomain domain = getClass().getProtectionDomain();

		PermissionCollection perms = Policy.getPolicy().getPermissions(domain);

		Enumeration<Permission> elements = perms.elements();
		while (elements.hasMoreElements()) {
			Permission permission = elements.nextElement();
			log.debug("permission : {}", permission);
		}

		return perms;

	}

	public static final String PROP_HOST_MANIFEST = "HOST-INF/MANIFEST.MF";
	public static final String PROP_DEPLOY_CACHE = "deployment.user.cachedir";

	//

	private volatile Framework framework;

	private volatile int startLevel;

	//

	private String storage;

	protected String getStorageLocation() {
		if (storage == null) {
			final String jnlpDir = System.getProperty(PROP_DEPLOY_CACHE);
			final String cacheDir;
			if (jnlpDir == null) {
				cacheDir = "./target/storage";
			} else {
				String folder = this.getClass().getPackage().getName();
				cacheDir = jnlpDir + "/" + folder;
			}
			storage = cacheDir;
			log.debug("### storage : {}", getStorageLocation());
		}
		return storage;
	}

	protected String getStorageLockFile() {
		return "storage.lock";
	}

	private Manifest getHostManifest() throws Exception {
		URL manifestURL = getClass().getClassLoader().getResource(
				PROP_HOST_MANIFEST);
		log.debug("manifest : {}", manifestURL);
		InputStream input = manifestURL.openStream();
		Manifest manifest = new Manifest(input);
		return manifest;

	}

	private String getHostAttribute(String name) throws Exception {
		Attributes attributes = getHostManifest().getMainAttributes();
		String value = attributes.getValue(name);
		return value;
	}

	private String getExportPackages() throws Exception {
		String export = getHostAttribute("Export-Package");
		log.debug("export : {}", export);
		return export;
	}

	private void configureOsgiProvider(String name,
			final Map<String, Object> config) {

		if (name.contains("org.apache.felix")) {

			log.debug("osgi provider: felix");

			config.put("felix.cache.locking", "false");

			try {

				Class<?> klaz = getClass().getClassLoader().loadClass(
						"org.apache.felix.framework.SecurityActivator");
				Object activator = klaz.newInstance();
				List<Object> activatorList = new LinkedList<Object>();
				activatorList.add(activator);

				config.put("felix.systembundle.activators", activatorList);
				config.put("felix.security.permissionadmin", "false");
				config.put("felix.security.conpermadmin", "true");

				log.debug("osgi provider: felix security is activated");

			} catch (Throwable e) {

				log.debug("osgi provider: felix security is NOT available");

			}

		}

	}

	protected void osgiStartup() throws Exception {

		if (framework != null) {
			log.error("### osgi is already started");
			return;
		}

		ServiceLoader<FrameworkFactory> loader = ServiceLoader
				.load(FrameworkFactory.class);

		FrameworkFactory factory = loader.iterator().next();

		String name = factory.getClass().getName();

		Map<String, Object> config = new HashMap<String, Object>();

		// provider-specific
		configureOsgiProvider(name, config);

		// osgi generic
		config.put(Constants.FRAMEWORK_STORAGE, getStorageLocation());
		config.put(Constants.FRAMEWORK_SYSTEMPACKAGES_EXTRA,
				getExportPackages());

		framework = factory.newFramework(config);

		log.debug("### osgi init");
		framework.init();

		BundleContext context = framework.getBundleContext();

		Bundle[] bundlesPresent = context.getBundles();
		for (Bundle bundle : bundlesPresent) {
			log.debug("present : {} : {}", bundle, bundle.getState());
			if (isSystem(bundle)) {
				continue; // skip system bundle
			}
			if (isFragment(bundle)) {
				continue; // skip non-lifecycle bundle
			}
			bundle.stop();
		}

		log.debug("### osgi start");
		framework.start();

	}

	protected void osgiShutdown() throws Exception {

		if (framework == null) {
			log.error("### osgi is already stopped");
			return;
		}

		for (ServiceReference reference : serviceRefs.values()) {
			framework.getBundleContext().ungetService(reference);
		}
		serviceRefs.clear();

		for (ServiceRegistration registration : serviceRegs.values()) {
			registration.unregister();
		}
		serviceRegs.clear();

		framework.stop();
		framework.waitForStop(0);
		framework = null;

		log.debug("### osgi stop");

	}

	private void updateMaximumStartLevel(int startLevel) {
		if (this.startLevel < startLevel) {
			this.startLevel = startLevel;
		}
	}

	private int obtainMaximumStartLevel() {
		return this.startLevel;
	}

	protected void osgiActivate(URL featureURL, String featureName)
			throws Exception {

		log.debug("### osgi activate : {}", featureName);

		FeatureRepository repository = FEATURE.decode(featureURL);

		FeatureEntry entry = repository.findFeatureByName(featureName);

		Collection<FeatureBundle> featureBundles = entry.getBundles();

		BundleContext context = framework.getBundleContext();

		StartLevel starter = getFrameworkService(StartLevel.class);

		Set<Bundle> pendingBundles = new HashSet<Bundle>();

		for (FeatureBundle featureBundle : featureBundles) {

			String location = featureBundle.getLocation();
			int startLevel = featureBundle.getStartLevel();

			Bundle duplicate = findDuplicate(location);
			if (duplicate != null) {
				log.debug("duplicate : {}", duplicate);
				duplicate.uninstall();
			}

			log.debug("install : {}", location);
			Bundle bundle = context.installBundle(location);

			if (startLevel > 0) {
				updateMaximumStartLevel(startLevel);
				starter.setBundleStartLevel(bundle, startLevel);
			}

			pendingBundles.add(bundle);

		}

		for (Bundle bundle : pendingBundles) {
			if (isUpdatable(bundle)) {
				log.debug("update  : {}", bundle);
				bundle.update();
			}
		}

		for (Bundle bundle : pendingBundles) {
			if (isFragment(bundle)) {
				continue; // skip non-lifecycle bundle
			}
			log.debug("startup : {}", bundle);
			bundle.start();
		}

		starter.setStartLevel(obtainMaximumStartLevel());

	}

	protected void osgiDeactivate(URL featureURL, String featureName)
			throws Exception {

		log.debug("### osgi deactivate");

		FeatureRepository repository = FEATURE.decode(featureURL);

		FeatureEntry entry = repository.findFeatureByName(featureName);

		Collection<FeatureBundle> featureBundles = entry.getBundles();

		BundleContext context = framework.getBundleContext();

		Bundle[] frameworkBundles = context.getBundles();

		for (FeatureBundle featureBundle : featureBundles) {

			String location = featureBundle.getLocation();

			for (Bundle bundle : frameworkBundles) {

				if (isSystem(bundle)) {
					continue; // skip system bundle
				}

				if (bundle.getLocation().equalsIgnoreCase(location)) {
					log.debug("shutdown : {} : {}", bundle, bundle.getState());
					bundle.stop();
				}

			}

		}

	}

	private final Map<String, ServiceReference> serviceRefs = new ConcurrentHashMap<String, ServiceReference>();

	@SuppressWarnings("unchecked")
	protected <T> T getFrameworkService(Class<T> klaz) {

		if (framework == null || klaz == null) {
			return null;
		}

		BundleContext context = framework.getBundleContext();

		if (context == null) {
			return null;
		}

		String name = klaz.getName();

		ServiceReference reference = serviceRefs.get(name);

		if (reference != null) {
			return (T) context.getService(reference);
		}

		reference = context.getServiceReference(klaz.getName());

		if (reference != null) {
			serviceRefs.put(name, reference);
			return (T) context.getService(reference);
		}

		return null;

	}

	private final Map<String, ServiceRegistration> serviceRegs = new ConcurrentHashMap<String, ServiceRegistration>();

	protected <T> void osgiRegister(Class<T> klaz, T service,
			Dictionary<String, String> properties) throws Exception {

		if (framework == null || klaz == null || service == null) {
			log.error("framework == null || klaz == null || service == null");
			return;
		}

		String name = klaz.getName();

		if (serviceRegs.containsKey(name)) {
			log.error("serviceRegs.containsKey(name)");
			return;
		}

		ServiceRegistration registration = framework.getBundleContext()
				.registerService(name, service, properties);

		serviceRegs.put(name, registration);

	}

	private static boolean isSystem(Bundle bundle) {
		return bundle.getBundleId() == 0;
	}

	private static boolean isFragment(Bundle bundle) {
		return bundle.getHeaders().get(Constants.FRAGMENT_HOST) != null;
	}

	private static boolean isUpdatable(Bundle bundle) {
		if (isDevelopment(bundle.getLocation())) {
			return true; // update development
		}
		if (isSnapshot(bundle.getVersion().getQualifier())) {
			return true; // update snapshots
		}
		return false;
	}

	private static boolean isConnectable(String location) {
		try {
			URL url = new URL(location);
			URLConnection connection = url.openConnection();
			return true;
		} catch (Exception e) {
			return false;
		}
	}

	/** duplicate: bundle with the same file name but at a different location */
	private Bundle findDuplicate(String locationNew) throws Exception {
		Bundle[] bundles = framework.getBundleContext().getBundles();
		for (Bundle bundle : bundles) {
			if (isSystem(bundle)) {
				continue; // skip system bundle
			}
			if (isDevelopment(locationNew)) {
				continue; // skip development
			}
			String locationOld = bundle.getLocation();
			if (locationOld.equals(locationNew)) {
				continue; // skip identical
			}
			String fileNew = getFileName(locationNew);
			String fileOld = getFileName(locationOld);
			// log.debug("fileNew : {}", fileNew);
			// log.debug("fileOld : {}", fileOld);
			if (fileOld.equals(fileNew)) {
				return bundle; // duplicate
			}
		}
		return null; // no duplicates
	}

	private static boolean isDevelopment(String location) {
		if (location.contains("reference:")) {
			return true;
		}
		return false;
	}

	private static boolean isSnapshot(String qualifier) {
		if (qualifier.contains("SNAPSHOT")) {
			return true;
		}
		return false;
	}

	private String getFileName(String location) {
		return location.substring(location.lastIndexOf('/'));
	}

}
