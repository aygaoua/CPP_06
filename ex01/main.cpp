#include "Serializer.hpp"

int main(){
    // Serializer k;

    Data *ptr = new Data();
    ptr->data_int = 1337;
    std::cout << "---->`" << ptr << "`<----\n";
    std::cout << "---->`" << ptr->data_int << "`<----\n";
    uintptr_t raw;

    raw = Serializer::serialize(ptr);

    std::cout << "---->`0x" << std::hex << raw  << "`<----\n";

    return (0);
}
