#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() {};

Contact::~Contact() {};

int Contact::GetID() const {
	return _id;
}

std::string Contact::GetFirstName() const {
	return _firstname;
}

std::string Contact::GetLastName() const {
	return _lastname;
}

std::string Contact::GetNickname() const {
	return _nickname;
}

std::string Contact::GetPhoneNumber() const {
	return _phonenumber;
}

std::string Contact::GetDarkestSecret() const {
	return _darkestsecret;
}

bool Contact::SetID(int id) {
	_id = id;
	return true;
}

bool Contact::SetFirstName(std::string firstname) {
	if (firstname.empty()) {
		return false;
	}
	_firstname = firstname;
	return true;
}

bool Contact::SetLastName(std::string lastname) {
	if (lastname.empty()) {
		return false;
	}
	_lastname = lastname;
	return true;
}

bool Contact::SetNickname(std::string nickname) {
	if (nickname.empty()) {
		return false;
	}
	_nickname = nickname;
	return true;
}

bool Contact::SetPhoneNumber(std::string phonenumber) {
	if (phonenumber.empty()) {
		return false;
	}	
	_phonenumber = phonenumber;
	return true;
}

bool Contact::SetDarkestSecret(std::string darkestsecret) {
	if (darkestsecret.empty()) {
		return false;
	}	
	_darkestsecret = darkestsecret;
	return true;
}