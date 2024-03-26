#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

class Form;

class Bureaucrat {

private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat( std::string name);
	Bureaucrat( std::string name, int grade);
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat& operator=(const Bureaucrat &bureaucrat);

	void		incrementGrade( const int );
	void		decrementGrade( const int );

	std::string getName() const;
	int			getGrade() const;

	void		signForm( Form & ) const;

	class GradeTooHighException : public std::exception {

	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {

	public:
        virtual const char* what() const throw ();
	};

};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
