# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

int main( void )
{
	{
		try {
        	Bureaucrat bureaucrat("MyNameIsOne", HIGEST_GRADE);
			std::cout << bureaucrat << std::endl;
    	}
    	catch (std::exception &e){
        	std::cout << "EXCEPTION: " << e.what() << std::endl;
    	}
	}
	{
		try {
        	Bureaucrat bureaucrat("MyNameIsTwo", LOWEST_GRADE);
			std::cout << bureaucrat << std::endl;
    	}
    	catch (std::exception &e) {
        	std::cout << "EXCEPTION: " << e.what() << std::endl;
    	}
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsThree", LOWEST_GRADE);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
        	Bureaucrat bureaucrat("MyNameIsFour", HIGEST_GRADE - 1);
			std::cout << bureaucrat << std::endl;
		} 
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
        	Bureaucrat bureaucrat("MyNameIsFive", LOWEST_GRADE + 1);
			std::cout << bureaucrat << std::endl;
    	} 
    	catch (std::exception &e){
        	std::cout << "EXCEPTION: " << e.what() << std::endl;
    	}
	}
	{
		try {
        	Bureaucrat bureaucrat("MyNameIsSix", LOWEST_GRADE + 1);
			std::cout << bureaucrat << std::endl;
    	} 
    	catch (std::exception &e){
        	std::cout << "EXCEPTION: " << e.what() << std::endl;
    	}
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsSeven", HIGEST_GRADE);
    		std::cout << bureaucrat << std::endl;			
			bureaucrat.incrementGrade(1);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}		
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsEighth", 2);
			std::cout << bureaucrat << std::endl;			
			bureaucrat.incrementGrade(1);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsNine", 149);
			std::cout << bureaucrat << std::endl;			
			bureaucrat.incrementGrade(1);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsTen", 149);
			std::cout << bureaucrat << std::endl;			
			bureaucrat.decrementGrade(1);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bureaucrat("MyNameIsEleven", 149);
			std::cout << bureaucrat << std::endl;			
			bureaucrat.decrementGrade(2);
		}
		catch (std::exception &e){
			std::cout << "EXCEPTION: " << e.what() << std::endl;
		}
	}

    return 0;
}
