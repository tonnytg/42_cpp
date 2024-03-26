# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main( void )
{

	{
		std::cout << "Test1:" << std::endl;
		try {
			Form form("Test1", LOWEST_GRADE, HIGEST_GRADE);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}

		try {
			Form form("Test1", HIGEST_GRADE, HIGEST_GRADE);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test2:" << std::endl;
		try {
			Form form("Test2", HIGEST_GRADE - 1, HIGEST_GRADE);
		} 
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}

		try {
			Form form("Test2", LOWEST_GRADE + 1, HIGEST_GRADE);
		} 
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test3:" << std::endl;
		Form form("Test3", 3, HIGEST_GRADE);

		std::cout << form << std::endl;
	}
	{
		std::cout << "Test4:" << std::endl;
		Form form("Bureaucrat form", LOWEST_GRADE, HIGEST_GRADE);
		Bureaucrat employee("MyClient", 39);

		try {
			form.beSigned(employee);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test5:" << std::endl;
		Form form("Bureaucrat form", 39, HIGEST_GRADE);
		Bureaucrat employee("MyClient", 100);

		try {
			form.beSigned(employee);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test6:" << std::endl;
		Form form("Bureaucrat form", 11, HIGEST_GRADE);
		Bureaucrat employee("42employee", 91);

		employee.signForm(form);
	}
	{
		std::cout << "Test7:" << std::endl;
		Form form("Bureaucrat form", HIGEST_GRADE, HIGEST_GRADE);
		Bureaucrat employee("MyClient", 3);

		employee.signForm(form);
	}
	{
		std::cout << "Test8:" << std::endl;
		Form form("Bureaucrat form", 99, HIGEST_GRADE);
		Bureaucrat employee("MyClient", 1);

		employee.signForm(form);

		try {
			employee.signForm(form);
		} catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
}
