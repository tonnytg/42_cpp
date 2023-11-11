#include <iostream>
#include <string>
#include <cctype>

class Argument {
private:
	std::string _value;

public:
	Argument() {}

	Argument(const char* arg) : _value(arg) {}

	Argument(const Argument& other) : _value(other._value) {}

	Argument& operator=(const Argument& other) {
		if (this != &other) {
			_value = other._value;
		}
		return *this;
	}
	~Argument() {}

	void toUpper() {
		for (size_t i = 0; i < _value.size(); i++) {
			_value[i] = std::toupper(_value[i]);
		}
	}

	const std::string getValue() const {
		return _value;
	}
};

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		Argument arg(argv[i]);
		arg.toUpper();
		std::cout << arg.getValue() << " ";
	}
	std::cout << std::endl;

	// Chama todos os destrutores
	// ...

	return 0;
}
