#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
class Intern
{
private:
    /* data */
public:
    Intern(/* args */);
    ~Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    //     the makeForm() function. It takes
    // two strings. The first one is the name of a form and the second one is the target of the
    // form. It return a pointer to a Form object (whose name is the one passed as parameter)
    // whose target will be initialized to the second parameter.
    // It will print something like:
    // Intern creates <form>

    Form *makeForm(std::string name, std::string target);
};

#endif
