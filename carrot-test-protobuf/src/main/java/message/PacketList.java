package message;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import com.example.tutorial.MessageProto.Packet;
import com.example.tutorial.MessageProto.Store;

class PacketList {

	static void print(Store store) {

		for (final Packet packet : store.getPacketList()) {

			// System.out.println("Person ID: " + person.getId());
			// System.out.println("  Name: " + person.getName());

			// if (person.hasEmail()) {
			// System.out.println("  E-mail address: " + person.getEmail());
			// }

			System.out.println("packet=\n" + packet);

		}
	}

	// Main function: Reads the entire address book from a file and prints all
	// the information inside.
	public static void main(String[] args0) throws Exception {

		final String name = "target/store-file.bin";

		final Store.Builder storeMaker = Store.newBuilder();

		try {
			final FileInputStream input = new FileInputStream(name);
			storeMaker.mergeFrom(input);
			input.close();
		} catch (final FileNotFoundException e) {
			System.out
					.println(name + ": File not found.  Creating a new file.");
		}

		print(storeMaker.build());

	}

}
