#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
    Data d(42);
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Convert to uintptr_t:" << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Original data value: " << d.getN() << std::endl;
    std::cout << "Data address: " << &d << std::endl;
    std::cout << "Pointer address " << ptr << std::endl;
    std::cout << "Deserialized value: " << ptr->getN() << std::endl;
    if (ptr == &d)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization fail!" << std::endl;
    return 0;
}