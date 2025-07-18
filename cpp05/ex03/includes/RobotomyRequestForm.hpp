#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>
class RobotomyRequestForm : public Form
{
private:
    std::string target;
public:
    RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    
     void execute(Bureaucrat const & executor) const ;
};

#endif