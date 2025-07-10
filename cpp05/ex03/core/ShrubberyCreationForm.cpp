#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include "../includes/Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shruby", 145, 137), target(target)
{
    std::cout << target << " has been shrubyzed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "destructor ShrubberyCreationForm is called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGrade_execute()) 
        throw GradeTooLowException();
    std::ofstream of((target + "_shrubbery").c_str());
    of << "	          &&& &&  & &&\n"
       << "      && &\\/&\\|& ()|/ @, &&\n"
       << "      &\\/(/&/&||/& /_/)_&/_&\n"
       << "   &() &\\/&|()|/&\\/ '%\" & ()\n"
       << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
       << "&&   && & &| &| /& & % ()& /&&\n"
       << " ()&_---()&\\&\\|&&-&&--%---()~\n"
       << "     &&     \\|||\n"
       << "             |||\n"
       << "             |||\n"
       << "             |||\n"
       << "       , -=-~  .-^- _\"\n";
    of.close();
    std::cout << "Shrubbery created at " << target << std::endl;
}
