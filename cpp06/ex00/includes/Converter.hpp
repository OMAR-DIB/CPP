#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

class Converter
{
private:
    Converter(/* args */);
    /* data */
public:
    static void convert_integer(const std::string& literal);
    static void	convertChar(const std::string& literal);
    static void	convert_float(const std::string& literal);
    static void	convert_double(const std::string& literal);
    static void convert_special(const std::string& literal);    
};



#endif