#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
protected:
    std::string	_ideas[100];

public:
    Brain();
    Brain(const Brain &brain);
    virtual ~Brain();
    Brain& operator=(Brain const & src);

    const std::string &getIdeas(int const &index) const;
    bool setIdeas(const std::string &idea, int index);
};

#endif