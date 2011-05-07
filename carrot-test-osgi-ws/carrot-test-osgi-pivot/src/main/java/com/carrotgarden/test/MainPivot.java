package com.carrotgarden.test;

import java.util.HashMap;
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

public class MainPivot implements Application {

	public static void initOsgi() {

		try {

			ServiceLoader<FrameworkFactory> loader = ServiceLoader
					.load(FrameworkFactory.class);

			FrameworkFactory factory = loader.iterator().next();

			Map<String, Object> config = new HashMap<String, Object>();

			config.put(Constants.FRAMEWORK_STORAGE, "./target/storage");

			Framework framework = factory.newFramework(config);

			framework.start();

			BundleContext context = framework.getBundleContext();

			Bundle bundle = context
					.installBundle("http://www.eclipsezone.com/files/jsig/bundles/HelloWorld.jar");

			bundle.start();

			framework.waitForStop(0);

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static void main(String... args) {

		String[] list = new String[] { MainPivot.class.getName() };

		DesktopApplicationContext.main(list);

	}

	private Window window;

	@Override
	public void startup(Display display,
			org.apache.pivot.collections.Map<String, String> properties)
			throws Exception {

		BXMLSerializer bxmlSerializer = new BXMLSerializer();

		window = (Window) bxmlSerializer.readObject(MainPivot.class,
				"MainPivot.xml");

		window.open(display);

	}

	@Override
	public boolean shutdown(boolean optional) throws Exception {

		if (window != null) {
			window.close();
		}

		return false;

	}

	@Override
	public void suspend() throws Exception {
		// TODO Auto-generated method stub

	}

	@Override
	public void resume() throws Exception {
		// TODO Auto-generated method stub

	}

}
