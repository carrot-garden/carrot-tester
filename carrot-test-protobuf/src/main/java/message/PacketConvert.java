package message;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

import org.joda.time.format.DateTimeFormat;
import org.joda.time.format.DateTimeFormatter;

import com.example.tutorial.MessageProto.Packet;
import com.example.tutorial.MessageProto.Packet.Builder;
import com.example.tutorial.MessageProto.Store;

class PacketConvert {

	static void print(final Store store) {

		for (final Packet packet : store.getPacketList()) {

			System.out.println("packet=\n" + packet);

		}
	}

	// 01/09/11 00:00:10
	static DateTimeFormatter format = DateTimeFormat
			.forPattern("dd/MM/YY HH:mm:ss");

	static final String source = "/home/user1/Trader/broker/Oanda/data/download-02/EEBF87536F220E0FA6616E1E3A7B071D.csv";
	static final String target = "target/convert-file.bin";

	static void convert() throws Exception {

		final FileReader reader = new FileReader(source);
		final BufferedReader bufIn = new BufferedReader(reader);

		//

		final FileOutputStream output = new FileOutputStream(target, false);

		// final BufferedOutputStream bufOut = new BufferedOutputStream(output);

		final GZIPOutputStream zipOut = new GZIPOutputStream(output);

		// final DeflaterOutputStream zipOut = new DeflaterOutputStream(bufOut);

		//

		int count = 0;

		while (true) {

			final String line = bufIn.readLine();

			if (line == null) {
				break;
			}

			final String[] terms = line.split(",");

			final String timeStr = terms[0];
			final String bidStr = terms[1];
			final String askStr = terms[2];

			final Builder maker = Packet.newBuilder();

			maker.setTime(format.parseMillis(timeStr));

			// maker.setBid(Float.parseFloat(bidStr));
			// maker.setAsk(Float.parseFloat(askStr));

			maker.build().writeDelimitedTo(zipOut);

			if (count % 100000 == 0) {
				System.out.println("count=" + count);
			}

			count++;

		}

		System.out.println("count=" + count);

		zipOut.close();

	}

	static void verify() throws Exception {

		final FileInputStream input = new FileInputStream(target);

		// final BufferedInputStream bufIn = new BufferedInputStream(input);

		final GZIPInputStream zipIn = new GZIPInputStream(input);

		// final InflaterInputStream zipIn = new InflaterInputStream(input);

		int count = 0;

		final long start = System.nanoTime();

		while (true) {

			final Packet packet = Packet.parseDelimitedFrom(zipIn);

			if (packet == null) {
				break;
			}

			if (count % 100000 == 0) {
				System.out.println("count=" + count);
			}

			count++;

		}

		final long finish = System.nanoTime();

		input.close();

		final long rate = (finish - start) / count;

		System.out.println("count=" + count + " rate=" + rate + " ns");

	}

	public static void main(final String[] args0) throws Exception {

		convert();

		verify();

	}

}
