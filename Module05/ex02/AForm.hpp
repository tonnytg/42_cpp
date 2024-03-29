#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <stdlib.h> 

class Bureaucrat;

class AForm {

private:

	const std::string	_name;
	bool                _isSigned;
	const int			_requiredGradeToSign;
	const int	        _requiredGradeToExecute;

public:

	AForm( std::string, int, int );
	virtual ~AForm( void );

	AForm( const AForm& );
	AForm& operator=( const AForm& );

	std::string 		getName() const;
	bool				getIsSigned() const;
	int					getRequiredGradeToSign() const;
	int					getRequiredGradeToExecute() const;

	virtual std::string getTarget() const = 0;

    void				setIsSigned( bool ) ;

	void				beSigned( Bureaucrat const& );
	virtual void		execute( Bureaucrat const& ) const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
        const char* what() const throw ();
	};

	class AlreadySignedException : public std::exception {
	public:
        virtual const char* what() const throw ();
	};

	class NotSignedException : public std::exception {
	public:
        const char* what() const throw ();
	};
};

#endif
