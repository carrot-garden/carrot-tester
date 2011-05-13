package com.carrotgarden.osgi_host;

import org.apache.pivot.wtk.Application;
import org.apache.pivot.wtk.DesktopApplicationContext;
import org.apache.pivot.wtk.Display;

import com.carrotgarden.impl.HostServiceImpl;

public class MainPivot extends HostServiceImpl implements Application {

	static {
		log.info("load");
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

		log.info("### pivot startup");

		this.display = display;
		this.properties = properties;

		log.info("### properties : {}", properties);

		osgiStartup();

	}

	@Override
	public boolean shutdown(boolean optional) throws Exception {

		osgiShutdown();

		this.display = null;
		this.properties = null;

		log.info("### pivot shutdown");

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
