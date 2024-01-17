#include "phonebook.hpp"

int Phonebook::nextId = 1;

Phonebook::Phonebook() {
    for (int i = 0; i < 8; i++) {
        _contacts[i] = NULL;
    }
}

Phonebook::~Phonebook() {
    for (int i = 0; i < 8; i++) {
        delete _contacts[i];
    }
}

void Phonebook::Save(const std::string& name, const std::string& phone) {
    for (int i = 0; i < 8; i++) {
        if (_contacts[i] == NULL) {
            _contacts[i] = new Contact(nextId++, name, phone);
            return;
        }
    }
}

void Phonebook::Show() const {
    for (int i = 0; i < 8; i++) {
        if (_contacts[i] != NULL) {
            std::cout << "Phonebook[" << i << "]: ";
            _contacts[i]->ShowAllInfo();
        }
    }
}
