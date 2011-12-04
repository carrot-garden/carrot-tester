package book;

// See README.txt for information and build instructions.

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

import com.example.tutorial.AddressBookProtos.AddressBook;
import com.example.tutorial.AddressBookProtos.Person;

class AddPerson {

	// This function fills in a Person message based on user input.
	static Person PromptForAddress(BufferedReader stdin, PrintStream out)
			throws IOException {

		final Person.Builder person = Person.newBuilder();

		out.print("Enter person ID: ");
		person.setId(Integer.valueOf(stdin.readLine()));

		out.print("Enter name: ");
		person.setName(stdin.readLine());

		out.print("Enter email address (blank for none): ");
		final String email = stdin.readLine();
		if (email.length() > 0) {
			person.setEmail(email);
		}

		while (true) {

			out.print("Enter a phone number (or leave blank to finish): ");
			final String number = stdin.readLine();
			if (number.length() == 0) {
				break;
			}

			final Person.PhoneNumber.Builder phoneNumber = Person.PhoneNumber
					.newBuilder().setNumber(number);

			out.print("Is this a mobile, home, or work phone? ");
			final String type = stdin.readLine();
			if (type.equals("mobile")) {
				phoneNumber.setType(Person.PhoneType.MOBILE);
			} else if (type.equals("home")) {
				phoneNumber.setType(Person.PhoneType.HOME);
			} else if (type.equals("work")) {
				phoneNumber.setType(Person.PhoneType.WORK);
			} else {
				out.println("Unknown phone type.  Using default.");
			}

			person.addPhone(phoneNumber);
		}

		return person.build();

	}

	// Main function: Reads the entire address book from a file,
	// adds one person based on user input, then writes it back out to the same
	// file.
	public static void main(String[] args0) throws Exception {

		final String name = "target/book-file.bin";

		final AddressBook.Builder addressBook = AddressBook.newBuilder();

		// Read the existing address book.
		try {
			final FileInputStream input = new FileInputStream(name);
			addressBook.mergeFrom(input);
			input.close();
		} catch (final FileNotFoundException e) {
			System.out
					.println(name + ": File not found.  Creating a new file.");
		}

		// Add an address.
		addressBook.addPerson(PromptForAddress(new BufferedReader(
				new InputStreamReader(System.in)), System.out));

		// Write the new address book back to disk.
		final FileOutputStream output = new FileOutputStream(name);
		addressBook.build().writeTo(output);
		output.close();

	}

}
