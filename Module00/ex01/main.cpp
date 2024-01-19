#include <iostream>
#include "phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string command;
    std::string name;
    std::string phone;    

    while (true) {
        std::cout << "Digite um comando (ADD, SEARCH ou EXIT): ";
        std::cin >> command;

        if (command == "ADD") {

            std::cout << "Digite o nome do contato: ";
            std::cin >> name;
            std::cout << "Digite o telefone do contato: ";
            std::cin >> phone;
            if (!phonebook.AddContact(name, phone)) {
                std::cout << "Não há espaço para adicionar mais contatos." << std::endl;
            }
        } else if (command == "SEARCH") {
            phonebook.DisplayContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Comando inválido." << std::endl;
        }
    }

    return 0;
}
