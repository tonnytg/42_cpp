#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
private:
    Contact _contacts[7];

public:
    Phonebook();
    bool AddContact(const std::string& name, const std::string& phone);
    bool RemoveContact(const std::string& name);
    void DisplayContacts() const;
};

#endif
