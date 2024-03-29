#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
private:
    int _index;
    int _hasValue;
	Contact _contacts[8];

public:
    Phonebook();
    ~Phonebook();

    void Save(Contact contact);
    void ShowAllContacts();
};

#endif
