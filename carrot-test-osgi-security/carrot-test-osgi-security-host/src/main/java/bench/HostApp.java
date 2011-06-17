package bench;

public class HostApp extends HostOsgiFramework {

	public static void main(String... strings) throws Exception {

		HostApp app = new HostApp();

		app.test();

	}

	void test() throws Exception {

		osgiStartup();

		for (int k = 0; k < 3; k++) {
			log.debug("sleep : {}", k);
			Thread.sleep(1 * 1000);
		}

		osgiShutdown();

	}

}
