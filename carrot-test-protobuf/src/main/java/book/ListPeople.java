package book;

// See README.txt for information and build instructions.

import java.io.FileInputStream;

import com.example.tutorial.AddressBookProtos.AddressBook;
import com.example.tutorial.AddressBookProtos.Person;

class ListPeople {

	// Iterates though all people in the AddressBook and prints info about them.
	static void Print(AddressBook addressBook) {

		for (final Person person : addressBook.getPersonList()) {

			System.out.println("Person ID: " + person.getId());
			System.out.println("  Name: " + person.getName());

			if (person.hasEmail()) {
				System.out.println("  E-mail address: " + person.getEmail());
			}

			for (final Person.PhoneNumber phoneNumber : person.getPhoneList()) {

				switch (phoneNumber.getType()) {
				case MOBILE:
					System.out.print("  Mobile phone #: ");
					break;
				case HOME:
					System.out.print("  Home phone #: ");
					break;
				case WORK:
					System.out.print("  Work phone #: ");
					break;
				}
				System.out.println(phoneNumber.getNumber());

			}
		}
	}

	// Main function: Reads the entire address book from a file and prints all
	// the information inside.
	public static void main(String[] args0) throws Exception {

		final String name = "target/book-file.bin";

		// Read the existing address book.
		final AddressBook addressBook = AddressBook
				.parseFrom(new FileInputStream(name));

		Print(addressBook);

	}

}
