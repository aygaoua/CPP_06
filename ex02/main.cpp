#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base *base_ptr = generate();

    std::cout << "pointer :" << std::endl;
    identify(base_ptr);
    std::cout << "refrrence :" << std::endl;
    identify(*base_ptr);
}