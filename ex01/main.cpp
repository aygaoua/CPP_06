#include "Serializer.hpp"

int main(){
    Data *ptr = new Data();
    ptr->data_int = 1337;
    std::cout << "---->`" << ptr << "`<----\n";
    std::cout << "---->`" << ptr->data_int << "`<----\n";
    uintptr_t raw = Serializer::serialize(ptr);

    std::cout << "---->`0x" << std::hex << raw << std::dec << "`<----\n";

    Data *test = Serializer::deserialize(raw);

    std::cout << "---->`" << test << "`<----\n";
    std::cout << "---->`" << test->data_int <<  "`<----\n";

    delete ptr;
    return (0);
}
