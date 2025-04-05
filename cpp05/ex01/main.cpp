#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
int main() {
    try {
        // Test 1: Valid Form Creation
        std:: cout << "Test 1\n";
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;

        // Test 2: Bureaucrat attempts to sign the form (fails due to low grade)
        std:: cout << "Test 2\n";
        try {
        Bureaucrat john("John", 100);
        john.signForm(form1);
        } catch (const Form::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }

        // Test 3: Bureaucrat with a high enough grade signs the form
        std:: cout << "Test 3\n";
        Bureaucrat alice("Alice", 40); 
        alice.signForm(form1);
        std::cout << form1 << std::endl;

        // Test 4: Attempt to create a Form with too high a grade
        std:: cout << "Test 4\n";
        try {
            Form invalidForm1("Invalid High Grade", 0, 25);
        } catch (const Form::GradeTooHighException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test 5: Attempt to create a Form with too low a grade
        std:: cout << "Test 5\n";
        try {
            Form invalidForm2("Invalid Low Grade", 151, 25);
        } catch (const Form::GradeTooLowException &e) {
            std::cerr <<  "Exception: " <<  e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what();
    }
    return 0;
}
