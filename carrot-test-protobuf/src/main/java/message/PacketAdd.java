package message;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Random;

import com.example.tutorial.MessageProto.Packet;

class PacketAdd {

	static Random generator = new Random();

	static Packet make() throws Exception {

		final Packet.Builder packetMaker = Packet.newBuilder();

		packetMaker.setTime(System.currentTimeMillis());

		// packetMaker.setExp(-2);

		packetMaker.setBid(generator.nextInt(1000000));

		// packetMaker.setGap(generator.nextInt(1000));

		final Packet packet = packetMaker.build();

		System.out.println("packet=\n" + packet);

		return packet;

	}

	public static void main(String[] args0) throws Exception {

		final String name = "target/store-file.bin";

		//

		final Packet packetOut = make();

		final FileOutputStream output = new FileOutputStream(name, true);

		packetOut.writeDelimitedTo(output);

		output.close();

		//

		final FileInputStream input = new FileInputStream(name);

		while (true) {

			final Packet packetIn = Packet.parseDelimitedFrom(input);

			if (packetIn == null) {
				break;
			}

			System.out.println("packetIn=\n" + packetIn);

		}

	}

}
