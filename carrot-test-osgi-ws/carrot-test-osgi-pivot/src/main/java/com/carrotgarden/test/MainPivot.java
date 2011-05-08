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

	private void initOsgi() {

		try {

			ServiceLoader<FrameworkFactory> loader = ServiceLoader
					.load(FrameworkFactory.class);

			FrameworkFactory factory = loader.iterator().next();

			Map<String, Object> config = new HashMap<String, Object>();

			config.put(Constants.FRAMEWORK_STORAGE, getStorageLocation());

			framework = factory.newFramework(config);

			System.out.println("### osgi start");
			framework.start();

			BundleContext context = framework.getBundleContext();

			Bundle bundle = context
					.installBundle("http://www.eclipsezone.com/files/jsig/bundles/HelloWorld.jar");

			bundle.start();

			framework.waitForStop(0);
			System.out.println("### osgi stop");

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static void main(String... args) {

		String[] array = new String[] { MainPivot.class.getName() };

		DesktopApplicationContext.main(array);

	}

	@Override
	public void startup(Display display,
			org.apache.pivot.collections.Map<String, String> properties)
			throws Exception {

		System.out.println("### startup");

		BXMLSerializer bxmlSerializer = new BXMLSerializer();

		window = (Window) bxmlSerializer.readObject(MainPivot.class,
				"MainPivot.xml");

		window.open(display);

		Runnable osgiTask = new Runnable() {
			@Override
			public void run() {
				initOsgi();
			}
		};

		new Thread(osgiTask, "# osgi thread").start();

	}

	@Override
	public boolean shutdown(boolean optional) throws Exception {

		System.out.println("### shutdown");

		if (framework != null) {
			framework.stop();
			framework = null;
		}

		if (window != null) {
			window.close();
			window = null;
		}

		return false;

	}

	@Override
	public void suspend() throws Exception {

		System.out.println("### suspend");

	}

	@Override
	public void resume() throws Exception {

		System.out.println("### resume");

	}

}
