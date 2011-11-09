package com.carrotgarden.office;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.sun.star.comp.helper.Bootstrap;
import com.sun.star.lang.XMultiComponentFactory;
import com.sun.star.uno.XComponentContext;

public class Main {

	static final Logger log = LoggerFactory.getLogger(Main.class);

	public static void main(String[] args) throws Exception {

		// Get the remote office component context
		XComponentContext xContext = Bootstrap.bootstrap();

		// Get the remote office service manager
		XMultiComponentFactory xMCF = xContext.getServiceManager();

		// Get the root frame (i.e. desktop) of openoffice framework.
		Object oDesktop = xMCF.createInstanceWithContext(
				"com.sun.star.frame.Desktop", xContext);

		// Desktop has 3 interfaces. The XComponentLoader interface provides
		// ability to load components.
		// XComponentLoader xCLoader = (XComponentLoader) UnoRuntime
		// .queryInterface(XComponentLoader.class, oDesktop);

		log.debug("hello");

	}

}
