#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardon", 25, 5), target("Default") {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		target = other.target;
	return *this;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presen",25,5), target(target)
{
    std::cout << target <<" has been presented." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "destructor PresidentialPardonForm is called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGrade_execute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}