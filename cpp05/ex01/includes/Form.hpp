#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
private:
	std::string const name;
	bool is_signed;
	const int grade_sign;
	const int grade_execute;

public:
	// Canonical form
	Form(); // Default constructor
	Form(const Form& other); // Copy constructor
	Form& operator=(const Form& other) = delete; // Deleted assignment operator
	~Form(); // Destructor

	// Param constructor
	Form(std::string name, int grade_sign, int grade_execute);

	// Getters
	int getGrade_sign() const;
	int getGrade_excute() const;
	std::string getName() const;
	bool getSign() const;

	// Member function
	void beSigned(Bureaucrat &b);

	// Exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &rSym);

#endif