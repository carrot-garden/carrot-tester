package com.carrotgarden.impl;

import java.net.URL;
import java.util.concurrent.atomic.AtomicInteger;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Service;
import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Display;

import com.carrotgarden.api.host.HostAppService;
import com.carrotgarden.api.plugin.ShutdownService;

@Component
@Service
public class HostServiceProvider extends HostOsgiFramework implements
		HostAppService, HostFeatureService {

	protected volatile Display display;
	protected volatile Map<String, String> properties;

	//

	private void osgiActivate() throws Exception {

		log.debug("### osgi register @ init");

		osgiRegister(HostAppService.class, this, null);

		log.debug("### osgi activate @ init");

		String featureLocation = getProperty(PROP_REPO_LOCATION);
		String featureActivate = getProperty(PROP_REPO_ACTIVATE);

		String[] names = featureActivate.split(",");

		for (String name : names) {
			URL featuresURL = new URL(featureLocation);
			osgiActivate(featuresURL, name);
		}

	}

	//

	@Override
	public Display getDisplay() {
		return display;
	}

	@Override
	public Map<String, String> getProperties() {
		// this is already an ImmutableMap
		return properties;
	}

	private ShutdownService getShutdownService() {
		return getFrameworkService(ShutdownService.class);
	}

	protected boolean isShutdownServiceable() {
		return getShutdownService() != null;
	}

	protected void requestShutdown() {
		getShutdownService().requestShutdown();
	}

	//

	private final static boolean IS_DEBUG = false;

	//

	private static final AtomicInteger HOST_ID = new AtomicInteger(0);

	private int getHostId() {
		return HOST_ID.get();
	}

	{
		HOST_ID.getAndIncrement();
		log.debug("### new host : {}", getHostId());
	}

	private static final int COUNT = 10;
	private static final int DELAY = 1000;

	@Override
	protected void osgiStartup() {
		try {

			super.osgiStartup();

			osgiActivate();

		} catch (Throwable e) {
			log.error("", e);
		}
	}

	@Override
	protected void osgiShutdown() {
		try {

			super.osgiShutdown();

		} catch (Throwable e) {
			log.error("", e);
		}
	}

	@Override
	public void featureActivate(String featureURL, String featureName)
			throws Exception {
		throw new Exception("TODO");
	}

	@Override
	public void featureDeactivate(String featureURL, String featureName)
			throws Exception {
		throw new Exception("TODO");
	}

	@Override
	public String getProperty(String name) {
		return properties.get(name);
	}

}
