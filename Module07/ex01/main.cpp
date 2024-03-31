#include "iter.tpp"

int main( void ) {
    int arrayOfInt[] = {1, 2, 3, 4, 5};
    std::string arrayOfStrings[] = {"one", "two", "three", "four", "five"};

    ::iter(arrayOfInt, 5, print);
    ::iter(arrayOfStrings, 5, print);
    return (0);
}
