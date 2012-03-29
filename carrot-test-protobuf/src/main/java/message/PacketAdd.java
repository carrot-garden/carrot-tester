package message;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Random;

import com.example.tutorial.MessageProto;
import com.example.tutorial.MessageProto.Packet;
import com.example.tutorial.MessageProto.Price.Builder;

class PacketAdd {

	static Random generator = new Random();

	static Packet make() throws Exception {

		final Packet.Builder packetMaker = Packet.newBuilder();

		packetMaker.setTime(System.currentTimeMillis());

		// packetMaker.setExp(-2);

		final Builder priceBid = MessageProto.Price.newBuilder();
		priceBid.setMantissa(123);
		priceBid.setExponent(-2);

		final Builder priceAsk = MessageProto.Price.newBuilder();
		priceAsk.setMantissa(345);
		priceAsk.setExponent(-2);

		packetMaker.setPriceBid(priceBid.build());
		packetMaker.setPriceAsk(priceAsk.build());

		// packetMaker.setGap(generator.nextInt(1000));

		final Packet packet = packetMaker.build();

		return packet;

	}

	public static void main(final String[] args0) throws Exception {

		final String name = "target/store-file.bin";

		//

		final Packet packetOut = make();

		System.out.println("packet out=\n" + packetOut);

		final FileOutputStream output = new FileOutputStream(name, true);

		packetOut.writeDelimitedTo(output);

		output.close();

		//

		final FileInputStream input = new FileInputStream(name);

		while (true) {

			final Packet packetInp = Packet.parseDelimitedFrom(input);

			if (packetInp == null) {
				break;
			}

			System.out.println("packet inp=\n" + packetInp);

		}

	}

}
