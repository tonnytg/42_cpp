#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

class AForm;

class Bureaucrat {

private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat( std::string );
	Bureaucrat( std::string, int );
	~Bureaucrat( void );

	Bureaucrat(const Bureaucrat &);
	Bureaucrat& operator=(const Bureaucrat &);

	void		incrementGrade( const int );
	void		decrementGrade( const int );

	std::string getName() const;
	int			getGrade() const;

	void		signForm( AForm & form) const;

	void		executeForm( AForm const & form) const;

	class GradeTooHighException : public std::exception
	{

	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:
        virtual const char* what() const throw ();
	};

};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
