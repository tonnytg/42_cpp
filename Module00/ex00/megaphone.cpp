#include <iostream>
#include <string>
#include <cctype>

class Argument {
private:
    std::string _value;

public:
    Argument() {}
    ~Argument() {}

    void setValue(const std::string& value) {
        _value = value;
    }

    void toUpper() {
        for (size_t i = 0; i < _value.size(); i++) {
            _value[i] = std::toupper(_value[i]);
        }
    }

    const std::string& getValue() const {
        return _value;
    }
};

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            Argument argument;
            argument.setValue(argv[i]);
            argument.toUpper();
            std::cout << argument.getValue() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }

    return 0;
}
