#include "Array.hpp"

#include <iostream>
#include "Array.hpp"

int main(int, char**) {
	{
		std::cout << "1 - Creating empty array" << std::endl;
		Array<int> empty;
		std::cout << "\tSize of Empty Array: " << empty.size() << std::endl;
		try {
			std::cout << "\tTrying to access index 0: " << empty[0] << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Finish empty array\n---" << std::endl;
	}
	{
		std::cout << "2 - Creating five slots array" << std::endl;
		Array<int> fiveSlots(5);
		std::cout << "\tSize: " << fiveSlots.size() << std::endl;
		for (int i = 0; i < fiveSlots.size(); i++)
			fiveSlots[i] = i;
		for (int i = 0; i < fiveSlots.size(); i++)
			std::cout << "\tfive[" << i << "]: " << fiveSlots[i] << std::endl;
		std::cout << "Finish five slots array\n---" << std::endl;
	}
	{
		std::cout << "3 - Creating array of Strings" << std::endl;
		Array<std::string> stringsArray(3);
		std::cout << "\tSize: " << stringsArray.size() << std::endl;
		stringsArray[0] = "a";
		stringsArray[1] = "b";
		stringsArray[2] = "c";
		for (int i = 0; i < stringsArray.size(); i++)
			std::cout << "\tstrings[" << i << "]: " << stringsArray[i] << std::endl;
		std::cout << "Finish array of Strings\n---" << std::endl;
	}
	{
		std::cout << "4 - Creating array of Strings" << std::endl;
		Array<std::string> strings(3);
		std::cout << "\tSize: " << strings.size() << std::endl;
		strings[0] = "a";
		strings[1] = "b";
		strings[2] = "c";
		for (int i = 0; i < strings.size(); i++)
			std::cout << "\tstrings[" << i << "]: " << strings[i] << std::endl;
	
		Array<std::string> copy(strings);
		std::cout << "\tSize: " << copy.size() << std::endl;
		for (int i = 0; i < copy.size(); i++)
			std::cout << "\tcopy[" << i << "]: " << copy[i] << std::endl;

		std::cout << "\tstrings:\t" << &strings << std::endl;
		std::cout << "\tcopy:\t\t" << &copy << std::endl;    

		std::cout  << "Create assign array"  << std::endl;
		Array<std::string> assign;
		assign = strings;
		std::cout  << "Access assign array"  << std::endl;
		std::cout << "\tSize: " << assign.size() << std::endl;
		for (int i = 0; i < assign.size(); i++)
			std::cout << "\tassign[" << i << "]: " << assign[i] << std::endl;
		std::cout  << "Getting the arrays locations"  << std::endl;
		std::cout << "\tstrings:\t" << &strings << std::endl;
		std::cout << "\tassign:\t\t" << &assign << std::endl;
		std::cout << "Finish array of Strings\n---" << std::endl;
	}
	{
		std::cout  << "5 - Create array to fail"  << std::endl;
		Array<int> thisArrayWillFail(5);
		std::cout << "\tSize: " << thisArrayWillFail.size() << std::endl;
		for (int i = 0; i < thisArrayWillFail.size(); i++)
			thisArrayWillFail[i] = i;
		for (int i = 0; i < thisArrayWillFail.size(); i++)
			std::cout << "\thisArrayWillFail[" << i << "]: " << thisArrayWillFail[i] << std::endl;
		try {
			std::cout << "\tTrying to access index 5: " << thisArrayWillFail[5] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Finish array to fail\n---" << std::endl;
	}
}
