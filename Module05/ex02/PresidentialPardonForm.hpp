#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string			_target;

	static const int	requiredGradeToSign = 25;
	static const int	requiredGradeToExecute = 5;

public:
	PresidentialPardonForm( std::string );
	~PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm& );
	PresidentialPardonForm& operator=(const PresidentialPardonForm& );

	std::string getTarget() const;

    void	execute( Bureaucrat const& ) const;

	void	pardon( void ) const;
};

std::ostream& operator<<(std::ostream &, const PresidentialPardonForm &);

#endif
