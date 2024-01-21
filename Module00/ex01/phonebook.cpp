#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>


Phonebook::Phonebook() {
    _index = 0;
}

Phonebook::~Phonebook() {}

void Phonebook::Save(Contact contact) {
    if (_index == 8) {
        _index = 0;
    }
    _index++;
    contact.SetID(_index);
    _contacts[_index - 1] = contact;
}

void Phonebook::ShowAllContacts() {

    std::cout << std::left << std::setw(10) << "Index" << "|";
    std::cout << std::left << std::setw(10) << "First Name" << "|";
    std::cout << std::left << std::setw(10) << "Last Name" << "|";
    std::cout << std::left << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < 8; i++) {
        if (!_contacts[i].GetFirstName().empty()) {
            std::string firstName = _contacts[i].GetFirstName();
            std::string lastName = _contacts[i].GetLastName();
            std::string nickname = _contacts[i].GetNickname();

            // Limitar a largura das colunas e adicionar "..." se excederem 10 caracteres
            if (firstName.length() > 10) {
                firstName = firstName.substr(0, 7) + "...";
            }
            if (lastName.length() > 10) {
                lastName = lastName.substr(0, 7) + "...";
            }
            if (nickname.length() > 10) {
                nickname = nickname.substr(0, 7) + "...";
            }

            std::cout << std::left << std::setw(10) << _contacts[i].GetID() << "|";
            std::cout << std::left << std::setw(10) << firstName << "|";
            std::cout << std::left << std::setw(10) << lastName << "|";
            std::cout << std::left << std::setw(10) << nickname << std::endl;
        }
    }

	std::cout << "Insert ID you want more infos: ";
	int InputID;
	std::cin >> InputID;

	for (int i=0; i < 8; i++) {
		if (_contacts[i].GetID() == InputID) {
			std::cout << "ID: " << _contacts[i].GetID() << std::endl;
			std::cout << "First Name: " << _contacts[i].GetFirstName() << std::endl;
			std::cout << "Last Name: " << _contacts[i].GetLastName() << std::endl;
			std::cout << "Nickname: " << _contacts[i].GetNickname() << std::endl;
			std::cout << "Phone Number: " << _contacts[i].GetPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contacts[i].GetDarkestSecret() << std::endl;

		}
	}
}
