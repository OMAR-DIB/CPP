#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy",72,45), target(target)
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

