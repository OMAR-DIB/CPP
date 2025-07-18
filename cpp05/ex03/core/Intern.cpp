#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << " [Intern] constructor init" << std::endl;
}

Intern::~Intern()
{
    std::cout << " [Intern] destructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
    (void)other;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

Form *Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };
    
    // Here we check each form type and create the corresponding form.
    if (name == formNames[0]) {
        std::cout << "Intern creates " << formNames[0] << std::endl;
        return new PresidentialPardonForm(target);
    }
    if (name == formNames[1]) {
        std::cout << "Intern creates " << formNames[1] << std::endl;
        return new RobotomyRequestForm(target);
    }
    if (name == formNames[2]) {
        std::cout << "Intern creates " << formNames[2] << std::endl;
        return new ShrubberyCreationForm(target);
    }

    std::cout << "Form name not recognized!" << std::endl;
    return NULL;
}
