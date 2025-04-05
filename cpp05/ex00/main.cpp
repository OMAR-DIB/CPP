#include "./includes/Bureaucrat.hpp"

#include "./includes/Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b("b", 75);
        std::cout << b;
        
        b.incrementGrade();
        std::cout << "After incrementing grade: " << b;

        Bureaucrat a("a", 1);
        std::cout << a;
        a.incrementGrade();  // Should throw GradeTooHighException
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