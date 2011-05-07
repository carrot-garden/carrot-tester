package case_01;

import java.net.InetAddress;
import java.net.InterfaceAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class A {

	static {
		System.setProperty("java.net.preferIPv4Stack", "true");
	}

	static final Logger log = LoggerFactory.getLogger(A.class);

	/** you must select your interface name */
	static final InetAddress mainAddr = getInterfaceAddress("eth0");
	static final int mainPort = 10101;

	static final InetAddress groupAddr = getMulticastAddress("231.2.3.4");
	static final int groupPort = 30123;

	static InetAddress getInterfaceAddress(String name) {
		try {
			NetworkInterface face = NetworkInterface.getByName(name);
			return face.getInterfaceAddresses().get(0).getAddress();
		} catch (Exception e) {
			log.error("", e);
			return null;
		}
	}

	static InetAddress getMulticastAddress(String name) {
		try {
			return InetAddress.getByName(name);
		} catch (Exception e) {
			log.error("", e);
			return null;
		}
	}

	static void list() {

		try {

			Enumeration<NetworkInterface> netFaceList = NetworkInterface
					.getNetworkInterfaces();

			while (netFaceList.hasMoreElements()) {

				log.info("##############");

				NetworkInterface face = netFaceList.nextElement();
				log.info("face: {}", face);

				List<InterfaceAddress> addrList = face.getInterfaceAddresses();

				for (InterfaceAddress addr : addrList) {
					log.info("addr: {}", addr.getAddress());
					log.info("loop: {}", addr.getAddress().isLoopbackAddress());
					log.info("live: {}", addr.getAddress().isReachable(100));
				}

			}

		} catch (Exception e) {
			log.error("", e);
		}

	}

	public static void main(String[] args) throws Exception {

		list();

		log.debug("mainAddr: {}", mainAddr);

		log.debug("groupAddr: {}", groupAddr);

	}

}
