#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string _name;
    std::string _phone;

public:
	Contact();
	~Contact();
    std::string GetName() const;
	std::string GetPhone() const;
    void SetName(const std::string& name);
	void SetPhone(const std::string& phone);
};

#endif
