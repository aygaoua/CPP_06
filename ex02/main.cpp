#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base *base_ptr = generate();

    std::cout << "* :" << std::endl;
    identify(base_ptr);
    std::cout << "& :" << std::endl;
    identify(*base_ptr);
}