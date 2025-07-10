#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <iostream>
#include <string>

class Checker
{
private:
    /* data */
    Checker(/* args */);
public:
    static bool is_int(const std::string &literal);
    static bool is_float(const std::string &literal);
    static bool is_char(const std::string &literal);
    static bool is_double(const std::string &literal);
    bool has_digit_or_dot(const std::string &literal,size_t iterator);
    
    static int is_special(const std::string& str);
};





#endif