#ifndef PRESIDENTIALPARDINFORM_HPP
#define PRESIDENTIALPARDINFORM_HPP

#include "AForm.hpp"
#include <iostream>
class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    
    void execute(Bureaucrat const & executor) const ;
};

#endif