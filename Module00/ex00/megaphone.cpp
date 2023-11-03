#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string value(argv[i]);

		for (size_t j = 0; j < value.size() ; j++)
		{
			value.at(j) = toupper(value.at(j));
		}
		std::cout << value;
	}
	std::cout << std::endl;
	return (0);
}