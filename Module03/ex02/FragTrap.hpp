#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

private:
    std::string _name;

public:

    FragTrap();
    FragTrap(const std::string& name);
    ~FragTrap();

    void highFivesGuys(void);

};


#endif //FRAGTRAP_H
