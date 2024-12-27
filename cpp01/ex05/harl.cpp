#include "harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

std::string toLower(std::string& str) {
    std::string result = str;
    for(size_t i = 0; i < result.length(); i++) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

void Harl::complain( std::string level ){
    std::string allLevels[] = {"debug" , "info", "warning", "error"};
    typedef void (Harl::*harlComplain)();
    harlComplain allFunctions[] = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    int i = 0;

    std::string lev = toLower(level);
    while (i < 4)
    {
        if (lev == allLevels[i])
        {
            (this->*allFunctions[i])(); // Call the corresponding member function
            return ;
        }
        i++;
    }
    std::cout << "Invalid level: " << level << std::endl;
}