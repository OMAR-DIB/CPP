#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cerrno>
#include <cmath>


class ScalarConverter
{
private:
    /* data */
    ScalarConverter(/* args */);
public:
   static void convert(const std::string &literal);
};

#endif