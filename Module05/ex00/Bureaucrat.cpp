# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name) {
    this->_grade = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
    if (grade < HIGEST_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > LOWEST_GRADE)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat.getName()) {
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat)
        this->_grade = bureaucrat.getGrade();
    return (*this);
}

void Bureaucrat::incrementGrade( int increment ) {  
    if ((this->_grade - increment) < HIGEST_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade -= increment;
}

void Bureaucrat::decrementGrade( int decrement ) {
    if ((this->_grade + decrement) > LOWEST_GRADE)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade += decrement;
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade is too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is too Low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
