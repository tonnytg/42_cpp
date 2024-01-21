#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	int 		_id;
	std::string	_firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

public:

	Contact();
	~Contact();

	int 		GetID() const ;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickname() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;


	bool SetID(int id);
	bool SetFirstName(std::string firstname);
	bool SetLastName(std::string lastname);
	bool SetNickname(std::string nickname);
	bool SetPhoneNumber(std::string phonenumber);
	bool SetDarkestSecret(std::string darkestsecret);
};

#endif // CONTACT_HPP