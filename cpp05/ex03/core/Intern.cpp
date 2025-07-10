#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
Intern::Intern(/* args */)
{
    std::cout << " [Intern] constructor init" << std::endl;
}

Intern::~Intern()
{
    std::cout << " [Intern] destructor calles" << std::endl;
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

// the makeForm() function. It takes
// two strings. The first one is the name of a form and the second one is the target of the
// form. It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.
// It will print something like:
// Intern creates <form>

Form *Intern::makeForm(std::string name, std::string target){
    std::string formName[] = {"PresidentialPardonForm","RobotomyRequestForm","ShrubberyCreationForm"};
    int i = 0;
    for(; i< 3 ; i++){
        if (name == formName[i])
            break;
    }

    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
    default:
        return NULL;
    }
}
