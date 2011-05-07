package case_01;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BasicWriter {

	static {
		System.setProperty("java.net.preferIPv4Stack", "true");
	}

	private static final Logger log = LoggerFactory
			.getLogger(BasicWriter.class);

	public static void main(String... args) throws Exception {

		log.info("init");

		//

		DatagramSocket socket = new DatagramSocket(0, A.mainAddr);
		log.debug("isBound(): {}", socket.isBound());
		log.info("local: {}", socket.getLocalSocketAddress());
		log.info("remote: {}", socket.getRemoteSocketAddress());

		//

		InetSocketAddress groupPoint = //
		new InetSocketAddress(A.groupAddr, A.groupPort);
		log.debug("groupPoint: {}", groupPoint);

		//

		log.info("ready");

		while (true) {

			int size = 16;

			byte[] array = new byte[size];

			ByteBuffer buffer = ByteBuffer.wrap(array);

			buffer.putLong(System.currentTimeMillis());

			DatagramPacket packet = new DatagramPacket(array, size);

			packet.setSocketAddress(groupPoint);

			socket.send(packet);

			// log.debug("{}", array);

			Thread.sleep(1 * 1000);

		}

	}

}
