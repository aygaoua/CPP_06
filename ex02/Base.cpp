#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {

}

Base * generate(void) {
    Base *ptr;
    srand(time(0));
    if (rand() % 3 == 0) {
        ptr = new A();
    }
    else if (rand() % 3 == 1) {
        ptr = new B();
    }
    else {
        ptr = new C();
    }
    return (ptr);
}

void identify(Base* p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    if (a) {
        std::cout << "A" << std::endl;
    }
    else if (b) {
        std::cout << "B" << std::endl;
    }
    else if (c){
        std::cout << "C" << std::endl;
    }
    else {
        std::cout << "UNKNOWN !!" << std::endl;
    }
}

void identify(Base& p){
    try {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...) {}
    try {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}
    try {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...) {}
}