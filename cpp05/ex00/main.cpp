#include "./includes/Bureaucrat.hpp"

#include "./includes/Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob;
        
        bob.incrementGrade();
        std::cout << "After incrementing grade: " << bob;

        Bureaucrat alice("Alice", 1);
        std::cout << alice;
        alice.incrementGrade();  // Should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
        charlie.decrementGrade();  // Should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}