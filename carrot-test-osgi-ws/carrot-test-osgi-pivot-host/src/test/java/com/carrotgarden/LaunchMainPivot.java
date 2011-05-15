package com.carrotgarden;

import org.apache.pivot.wtk.DesktopApplicationContext;

import com.carrotgarden.osgi_host.MainPivot;

public class LaunchMainPivot {

	public static void main(String... args) {

		DesktopApplicationContext.main(MainPivot.class, args);

	}

}
