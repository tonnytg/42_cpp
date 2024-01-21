#include "Phonebook.hpp"
#include <iostream>

void PrintMenu() {
	std::cout << "Choose option (ADD, SEARCH or EXIT): ";
}

std::string GetInputOption() {
	std::string option;

	std::cin >> option;

	return option;
}

Contact GetInputContact() {
	Contact contact;
	std::string FirstName, LastName, Nickname, PhoneNumber, DarkestSecret;

	std::cout << "Insert First Name: ";
	std::cin >> FirstName;
	contact.SetFirstName(FirstName);

	std::cout << "Insert Last Name: ";
	std::cin >> LastName;
	contact.SetLastName(LastName);

	std::cout << "Insert Nickname: ";
	std::cin >> Nickname;
	contact.SetNickname(Nickname);

	std::cout << "Insert Phone Number: ";
	std::cin >> PhoneNumber;
	contact.SetPhoneNumber(PhoneNumber);

	std::cout << "Insert Darkest Secret: ";
	std::cin >> DarkestSecret;
	contact.SetDarkestSecret(DarkestSecret);		

	return contact;
}

int main() {

	Phonebook phonebook;

	std::string option;
	while (true) {

		PrintMenu();
		option = GetInputOption();

		if (option == "EXIT" ) {
			break;
		}
		if (option == "ADD") {
			std::cout << "ADD" << std::endl;

			Contact contact = GetInputContact();
			phonebook.Save(contact);
		}
		if (option == "SEARCH") {
			std::cout << "SEARCH" << std::endl;
			phonebook.ShowAllContacts();
		}
	}
	return 0;
}