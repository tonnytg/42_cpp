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

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName()) {
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopyFrom) {
    if (this != &toCopyFrom)
        this->_grade = toCopyFrom.getGrade();
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

void Bureaucrat::signForm( AForm &form ) const {
    try {
        form.beSigned(*this);
    }
    catch (const std::exception &e)
    {
        std::cout << "EXCEPTION: " << this->_name << " couldn’t sign " << form.getName() << " because Bureaucrat's grade isn't enough to sign this Form" << std::endl;
        return;
    }
    std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm( AForm const & form ) const {
    try {
        form.execute(*this);
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << "EXCEPTION: " << this->_name << " couldn’t execute " << form.getName() << " because Bureaucrat's grade is not high enough" << std::endl;
        return;
    }
    catch (const AForm::NotSignedException &e)
    {
        std::cout << "EXCEPTION: " << this->_name << " couldn’t execute " << form.getName() << " because the Form is not signed" << std::endl;
        return;
    }
    catch (const AForm::AlreadySignedException &e)
    {
        std::cout << "EXCEPTION: " << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << this->_name << " executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade is too High (the highest possible grade is 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is too Low (the lowest possible grade is 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
