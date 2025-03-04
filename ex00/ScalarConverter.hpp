#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter {
    private:
    /*----------------------- Orthodox Canonical Form -----------------------*/
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        ~ScalarConverter();
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        static void convert(const std::string &input);
    /*-----------------------------------------------------------------------*/

};
