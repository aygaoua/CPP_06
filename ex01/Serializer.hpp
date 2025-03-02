#pragma once
#include "Data.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <stdint.h>

class Serializer{
    private:
    /*----------------------- Orthodox Canonical Form -----------------------*/
        Serializer		();
		Serializer		(Serializer const & src);
		Serializer&		operator =(const Serializer& b);
    public:
		~Serializer();
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        static    uintptr_t serialize(Data* ptr);
        static    Data* deserialize(uintptr_t raw);
    /*-----------------------------------------------------------------------*/
};

