#include "phonebook.hpp"

Contact::Contact(int id, const std::string& name, const std::string& phone) {
    _id = id;
    _name = name;
    _phone = phone;
}

Contact::~Contact() {}

void Contact::SetName(const std::string& name) {
    _name = name;
}

void Contact::SetPhone(const std::string& phone) {
    _phone = phone;
}

int Contact::GetId() const {
    return _id;
}

void Contact::ShowAllInfo() const {
    std::cout << "ID: " << _id << std::endl;
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Phone: " << _phone << std::endl;
}
