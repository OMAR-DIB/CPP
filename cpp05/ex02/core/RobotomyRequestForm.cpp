#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequest", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		target = other.target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy",72,45), target(target)
{
    std::cout << target <<" has been robotomized." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "destructor RobotomyRequestForm is called." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > getGrade_execute()) 
        throw GradeTooLowException();
    if (std::rand() % 2)
        std::cout << target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomize failed on " << target << "!" << std::endl;
}

