package com.carrotgarden.core.login;

import org.apache.pivot.beans.BXMLSerializer;
import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Application;
import org.apache.pivot.wtk.DesktopApplicationContext;
import org.apache.pivot.wtk.Display;
import org.apache.pivot.wtk.Window;

public class TestLoginWindow implements Application {

	public static void main(String... args) {

		DesktopApplicationContext.main(TestLoginWindow.class, args);

	}

	private Window window;

	@Override
	public void startup(Display display, Map<String, String> properties)
			throws Exception {

		BXMLSerializer bxml = new BXMLSerializer();

		window = (Window) bxml
				.readObject(LoginWindow.class, "LoginWindow.bxml");

		window.open(display);

	}

	@Override
	public boolean shutdown(boolean optional) throws Exception {
		return false;
	}

	@Override
	public void suspend() throws Exception {
	}

	@Override
	public void resume() throws Exception {
	}

}
