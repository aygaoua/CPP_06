#include "Serializer.hpp"

int main(){
    uintptr_t raw = 15;

    Data *ptr;
    ptr = Serializer::deserialize(raw);
    std::cout << ptr << "<----\n";

    Data *gg = Serializer::deserialize(raw);

    uintptr_t kk;

    kk = Serializer::serialize(gg);

    std::cout << kk << "<----\n";

    return (0);
}