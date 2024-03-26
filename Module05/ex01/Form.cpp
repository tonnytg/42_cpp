# include <iostream>
# include <exception>
# include "Form.hpp"

Form::Form( const std::string name, int requiredGradeToSign, int requiredGradeToExecute ) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute) {
    this->_isSigned = false;
    if (requiredGradeToSign < HIGEST_GRADE || requiredGradeToExecute < HIGEST_GRADE )
        throw (Form::GradeTooHighException());
    else if (requiredGradeToSign > LOWEST_GRADE || requiredGradeToExecute > LOWEST_GRADE)
        throw (Form::GradeTooLowException());
}

Form::~Form() {}

Form::Form(const Form &form) : _name(form.getName()),  _requiredGradeToSign(form.getRequiredGradeToSign()), _requiredGradeToExecute(form.getRequiredGradeToExecute()) {
    *this = form;
}

Form& Form::operator=(const Form &form) {
    if (this != &form)
        this->_isSigned = form.getIsSigned();
    return (*this);
}

std::string Form::getName( void ) const {
    return (this->_name);
}

bool Form::getIsSigned( void ) const {
    return (this->_isSigned);
}

int Form::getRequiredGradeToSign( void ) const {
    return (this->_requiredGradeToSign);
}

int Form::getRequiredGradeToExecute( void ) const {
    return (this->_requiredGradeToExecute);
}

void    Form::beSigned( const Bureaucrat& bureaucrat ) {
    if (this->_isSigned)
        throw (Form::AlreadySignedException());
    else if (bureaucrat.getGrade() > this->_requiredGradeToSign)
        throw (Form::GradeTooLowException());
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw () {
	return ("Form's grade is too High");
}

const char* Form::GradeTooLowException::what() const throw()  {
	return ("Form's grade is too Low");
}

const char* Form::AlreadySignedException::what() const throw() {
	return ("Form's is already signed.");
}

std::ostream& operator<<(std::ostream& os, const Form &form) {
	os << "Form " << form.getName() << ", form grade " << form.getRequiredGradeToSign() << " to sign and grade " << form.getRequiredGradeToExecute() << " to execute.";
	return os;
}