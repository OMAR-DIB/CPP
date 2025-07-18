#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "./AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>
class AForm;
class Bureaucrat
{
private:
    static const int min_grade = 1;
    static const int max_grade = 150;
    std::string const name;
    int grade;
public:
    Bureaucrat();
	Bureaucrat(std::string name,int grade);
    Bureaucrat(Bureaucrat& other);
	~Bureaucrat();
	std::string getName();
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	Bureaucrat& operator = (Bureaucrat& other);

	void signForm(AForm& f);

	void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};
std::ostream &	operator<<(std::ostream & o, Bureaucrat &rSym);




#endif