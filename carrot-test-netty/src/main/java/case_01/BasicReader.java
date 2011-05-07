package case_01;

import java.net.DatagramPacket;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.nio.ByteBuffer;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BasicReader {

	static {
		System.setProperty("java.net.preferIPv4Stack", "true");
	}

	private static final Logger log = LoggerFactory
			.getLogger(BasicReader.class);

	public static void main(String... args) throws Exception {

		log.info("init");

		//

		InetSocketAddress bindPoint = //
		// XXX MUST USE GROUP PORT on WINDOWS
		new InetSocketAddress(A.mainAddr, A.groupPort);
		log.debug("bindPoint: {}", bindPoint);

		InetSocketAddress groupPoint = //
		new InetSocketAddress(A.groupAddr, A.groupPort);

		log.debug("groupPoint: {}", groupPoint);

		//

		MulticastSocket socket = new MulticastSocket(null);
		log.info("isBound: {}", socket.isBound());

		switch (OS.detect()) {
		case LINUX:
			socket.bind(groupPoint);
			break;
		case WINDOWS:
			socket.bind(bindPoint);
			break;
		default:
			throw new RuntimeException("please define new os");
		}

		log.info("isBound: {}", socket.isBound());
		log.info("local: {}", socket.getLocalSocketAddress());
		log.info("remote: {}", socket.getRemoteSocketAddress());

		NetworkInterface bindInterface = //
		NetworkInterface.getByInetAddress(bindPoint.getAddress());
		log.info("bindInterface: {}", bindInterface);

		socket.joinGroup(groupPoint, bindInterface);

		//

		log.info("ready");

		while (true) {

			int size = 2 * 16;

			byte[] array = new byte[size];

			DatagramPacket packet = new DatagramPacket(array, size);

			socket.receive(packet);

			ByteBuffer buffer = ByteBuffer.wrap(array);

			long valaue = buffer.getLong();

			log.debug("{}", valaue);

		}

		// Thread.sleep(1000 * 1000);

	}

}
