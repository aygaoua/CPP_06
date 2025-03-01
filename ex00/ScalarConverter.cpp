#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {

    (void)other;
    /* no thing to copy */
    return *this;
}

ScalarConverter::~ScalarConverter() {

}

bool is_number(std::string s) {
    for (int c = 0; c != static_cast<int>(s.size()); ++c) {
        if (isdigit(static_cast<char>(s[c])) == 0 && static_cast<char>(s[c]) != '.') return false;
    }
    return true;
}

bool have_fract(double ff)
{
    // float i = f;
    double intPart = (long)ff;
    double fractionalPart = ff - intPart;

    if (fractionalPart == 0.0) {
        return (true);
    }
    return (false);
}

void ScalarConverter::convert (const std::string &input)
{
    static const std::string special[] = {"nan", "-inf", "+inf", "+inff", "nanf", "-inff"};

    for (int i = 0; i < 6; i++) {
        if (input == special[i]) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << ((i == 3 || i == 4 || i == 5) ? special[i] : special[i] + "f") << std::endl;
            std::cout << "double: " << ((i == 3 || i == 4 || i == 5) ? special[i].substr(0, special[i].length() - 1) : special[i]) << std::endl;
            return;
        }
    }

    if (input.length() == 3 && std::isprint(input[1]) && input[0] == '\'' && input[2] == '\'') 
    {
        char c = input[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    try {
        std::string temp = input;
        char* end_ptr;

        if (input == "f")
            throw ("Invalid input");
        if (input.length() != 0 && input[input.length() - 1] == 'f' && input.find('.', 0) != std::string::npos)
            temp = input.substr(0, input.length() - 1);
        double value = strtod(temp.c_str(), &end_ptr);
        if (*end_ptr || input == ".")
            throw ("Invalid input");

        if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
        {
            if (std::isprint(static_cast<int>(value)))
                std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
            else if (!std::isprint(static_cast<int>(value)))
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;

        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() || std::isnan(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;

        if ((value <= std::numeric_limits<float>::max()) && (value >= -std::numeric_limits<float>::max()))
            std::cout << "float: " << static_cast<float>(value) << (have_fract(static_cast<float>(value)) ? ".0f" : "f") << std::endl;
        else 
            std::cout << "float: " << (value > std::numeric_limits<float>::max() ? "+" : "") << static_cast<float>(value) << "f" <<std::endl;
        if (value <= std::numeric_limits<double>::max() && value >= -std::numeric_limits<double>::max())
            std::cout << "double: " << value << (have_fract(static_cast<double>(value)) ? ".0" : "") << std::endl;
        else
            std::cout << "double: " << value << std::endl;
    }
    catch (...) {
        std::cout << "Error: Invalid input" << std::endl;
    }
}