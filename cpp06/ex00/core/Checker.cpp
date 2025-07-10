#include "../includes/Checker.hpp"

bool Checker::is_int(const std::string &literal)
{
    int is_sign_present = 0;
    if (literal.at(0) == '-' || literal.at(0) == '+')
        is_sign_present = 1;
    // int i = 0;
    while (is_sign_present < (int)literal.length())
    {
        if (!isdigit((int)literal.at(is_sign_present)))
            return false;
        is_sign_present++;
    }
    return true;
}

bool Checker::is_char(const std::string &literal)
{
    if ((literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'') || (literal.length() == 1 && !isdigit(literal[0])))
    {
        return true;
    }
    return false;
}

bool Checker::is_float(const std::string &literal)
{
    std::cout << "enter" << std::endl;
    size_t len = literal.length();
    if (len < 2 || literal[len - 1] != 'f')
        return false;

    std::string num = literal.substr(0, len - 1);
    size_t i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;

    bool has_digit = false, has_dot = false;
    for (; i < num.length(); ++i)
    {
        if (isdigit(num[i]))
            has_digit = true;
        else if (num[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else
            return false;
    }
    return has_digit && has_dot;
}

bool Checker::is_double(const std::string &literal)
{
    size_t len = literal.length();
    if (len < 2)
        return false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    bool has_digit = false, has_dot = false;
    for (; i < len; ++i)
    {
        if (isdigit(literal[i]))
            has_digit = true;
        else if (literal[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else
            return false;
    }
    return has_digit && has_dot;
    // return has_digit_or_dot(literal,i);
}

// bool Checker::has_digit_or_dot(const std::string &literal,size_t iterator){
//     size_t len = literal.length();
//     if (len < 2)
//         return false;
//     bool has_digit = false, has_dot = false;
//     for (; iterator < len; ++iterator)
//     {
//         if (isdigit(literal[iterator]))
//             has_digit = true;
//         else if (literal[iterator] == '.')
//         {
//             if (has_dot)
//                 return false;
//             has_dot = true;
//         }
//         else
//             return false;
//     }
//     return has_digit && has_dot;
// }

int	Checker::is_special(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 1;
	return 0;
}