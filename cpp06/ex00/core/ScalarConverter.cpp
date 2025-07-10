#include "../includes/ScalarConverter.hpp"
#include "../includes/Checker.hpp"
#include "../includes/Converter.hpp"


void ScalarConverter::convert(const std::string &literal)
{
    if (Checker::is_int(literal))
		Converter::convert_integer(literal);
    else if(Checker::is_char(literal)){ 

            Converter::convertChar(literal);
    }else if (Checker::is_float(literal)) {
      std::cout << "Enter float" <<std::endl;
      Converter::convert_float(literal);
    }
    else if(Checker::is_double(literal)){
      std::cout << "Enter double" <<std::endl;
      Converter::convert_double(literal);
    }else if (Checker::is_special(literal)){
      Converter::convert_special(literal);
    }
}
