# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

int main( void )
{
	{
		try {
			AForm *form = new ShrubberyCreationForm("formTest1");
			form->getTarget();
			delete form;
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
			AForm *form = new PresidentialPardonForm("formTest2");
			form->getTarget();
			delete form;
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
			AForm *form = new RobotomyRequestForm("formTest3");
			form->getTarget();
			delete form;
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		Bureaucrat random("test1", 1);
		AForm *form = new ShrubberyCreationForm("test1");   
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat  random("test2", 1);
		AForm *form = new PresidentialPardonForm("test2");   
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat random("test3", 2);
		AForm *form = new RobotomyRequestForm("test3");   
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat random("test4", 121);
		AForm *form = new ShrubberyCreationForm("test4");   
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat  random("test5", 5);
		AForm *form = new PresidentialPardonForm("test5");
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat random("test6", 40);
		AForm *form = new RobotomyRequestForm("test6");
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat random("test7", 111);
		AForm *form = new ShrubberyCreationForm("test7");
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat  random("test8", 5);
		AForm *form = new PresidentialPardonForm("test8");
		random.executeForm(*form);
		delete form;
	}
	{
		Bureaucrat random("test9", 44);
		AForm *form = new RobotomyRequestForm("test9");
		random.executeForm(*form);
		delete form;
	}
}