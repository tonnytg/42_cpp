# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name) {
    this->_grade = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
    try {
        this->_grade = grade;
        if (this->_grade < HIGEST_GRADE)
        {
            this->_grade = HIGEST_GRADE;
            throw (Bureaucrat::GradeTooHighException());
        }
        else if (this->_grade > LOWEST_GRADE)
        {
            this->_grade = LOWEST_GRADE;
            throw (Bureaucrat::GradeTooLowException());
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
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

void    Bureaucrat::signForm( Form& form ) const {
    try {
        form.beSigned(*this);
    }
    catch (const Form::AlreadySignedException &e)
    {
        std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " couldn’t sign " << form.getName() << " because Bureaucrat's grade isn't enough to sign this Form" << std::endl;
        return;
    }
    std::cout << this->_name << " signed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade is too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is too Low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
