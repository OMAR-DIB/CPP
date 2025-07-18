
#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/AForm.hpp"
#include <iostream>

int main() {
    Bureaucrat john("John", 1);
    Bureaucrat jane("Jane", 140); 
    try {
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        john.signForm(shrubbery);
        
        john.executeForm(shrubbery);
    } catch (AForm::GradeTooHighException  &e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooLowException  &e) {
        std::cerr << e.what() << std::endl;
    }
    
    try{
        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        RobotomyRequestForm robotomy("John's brain");
        john.signForm(robotomy);
        john.executeForm(robotomy); 

        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        PresidentialPardonForm pardon("Zaphod Beeblebrox");
        john.signForm(pardon);
        john.executeForm(pardon);

    } catch (AForm::GradeTooHighException  &e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooLowException  &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}