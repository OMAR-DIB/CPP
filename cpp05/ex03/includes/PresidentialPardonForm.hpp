#ifndef PRESIDENTIALPARDINFORM_HPP
#define PRESIDENTIALPARDINFORM_HPP

#include "Form.hpp"
#include <iostream>
class PresidentialPardonForm : public Form
{
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    
    void execute(Bureaucrat const & executor) const ;
};

#endif