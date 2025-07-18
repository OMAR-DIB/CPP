#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <iostream>
class ShrubberyCreationForm : public Form
{
private:
    std::string target;
public:
// Canonical form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

    ShrubberyCreationForm(std::string target);
    
    void execute(Bureaucrat const & executor) const ;
    
};

#endif