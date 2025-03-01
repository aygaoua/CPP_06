#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);

};
