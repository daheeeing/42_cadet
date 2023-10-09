#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iomanip>
#include <limits>
#include <iostream>

class ScalarConverter
{
    private:

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
		ScalarConverter& operator=(const ScalarConverter& ref);
		~ScalarConverter();
};

#endif