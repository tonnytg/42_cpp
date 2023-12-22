#include <iostream>
#include <string>
#include <cctype>
#include <gtest/gtest.h>

class Argument {
private:
    std::string _value;

public:
    Argument() = default;
    Argument(const char* arg) : _value(arg) {}
    Argument(const Argument& other) : _value(other._value) {}
    Argument& operator=(const Argument& other) {
        if (this != &other) {
            _value = other._value;
        }
        return *this;
    }

    ~Argument() = default;

    void toUpper() {
        for (size_t i = 0; i < _value.size(); i++) {
            _value[i] = std::toupper(_value[i]);
        }
    }

    const std::string& getValue() const {
        return _value;
    }
};

TEST(ArgumentTest, ToUpper) {
    Argument arg("test");
    arg.toUpper();
    ASSERT_EQ(arg.getValue(), "TEST");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
