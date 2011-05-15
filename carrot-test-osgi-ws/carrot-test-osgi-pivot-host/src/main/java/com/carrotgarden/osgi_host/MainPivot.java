package com.carrotgarden.osgi_host;

import java.net.URL;

import org.apache.pivot.wtk.Application;
import org.apache.pivot.wtk.Display;

import com.carrotgarden.impl.HostServiceProvider;

public class MainPivot extends HostServiceProvider implements Application {

	static {
		log.info("load");
	}

	private void osgiActivate() throws Exception {

		String featuresRepo = properties.get("deployment.features");
		String featuresActive = properties.get("deployment.features.names");

		String[] names = featuresActive.split(",");

		for (String name : names) {
			URL featuresURL = new URL(featuresRepo);
			osgiActivate(featuresURL, name);
		}

	}

	@Override
	public void startup(Display display,
			org.apache.pivot.collections.Map<String, String> properties)
			throws Exception {

		System.gc();

		log.info("### pivot startup");

		this.display = display;
		this.properties = properties;

		log.info("### properties : {}", properties);

		osgiStartup();

		osgiActivate(); //

	}

	@Override
	public boolean shutdown(boolean isOptional) throws Exception {

		if (isOptional && !isShutdownConfirmed()) {
			return true; // do not shutdown
		}

		osgiShutdown();

		this.display = null;
		this.properties = null;

		log.info("### pivot shutdown; optional : {}", isOptional);

		System.gc();

		return false;

	}

	@Override
	public void suspend() throws Exception {
		// not used
	}

	@Override
	public void resume() throws Exception {
		// not used
	}

}
