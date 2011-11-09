package com.carrotgarden.bench;

import java.awt.Color;
import java.awt.Font;

import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Application;
import org.apache.pivot.wtk.DesktopApplicationContext;
import org.apache.pivot.wtk.Display;
import org.apache.pivot.wtk.HorizontalAlignment;
import org.apache.pivot.wtk.Label;
import org.apache.pivot.wtk.VerticalAlignment;
import org.apache.pivot.wtk.Window;

public class HelloJava implements Application {

	private Window window = null;

	private Display display;

	@Override
	public void startup(final Display display,
			final Map<String, String> properties) {

		this.display = display;

		makeWindow(10);

	}

	void makeWindow() {

		if (window != null) {
			window.close();
			window = null;
		}

		window = new Window();

		Label label = new Label();
		label.setText("Hello World!");
		label.getStyles().put("font", new Font("Arial", Font.BOLD, 24));
		label.getStyles().put("color", Color.RED);
		label.getStyles()
				.put("horizontalAlignment", HorizontalAlignment.CENTER);
		label.getStyles().put("verticalAlignment", VerticalAlignment.CENTER);

		window.setContent(label);

		window.setTitle("Hello World!");
		window.setMaximized(true);

		window.open(display);

	}

	void makeWindow(int count) {

		for (int k = 0; k < count; k++) {
			makeWindow();
		}

	}

	@Override
	public boolean shutdown(boolean optional) {

		return false;
	}

	@Override
	public void suspend() {
	}

	@Override
	public void resume() {
	}

	public static void main(String... args) {

		String[] list = new String[] { HelloBXML.class.getName() };

		DesktopApplicationContext.main(list);

	}

}
