#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	std::string const name;
	bool is_signed;
	const int grade_sign;
	const int grade_execute;

public:
	// Canonical form
	AForm(); // Default constructor
	AForm(const AForm& other); // Copy constructor
	AForm& operator=(const AForm& other) = delete; // Deleted assignment operator
	virtual ~AForm(); // Virtual destructor

	// Param constructor
	AForm(std::string name, int grade_sign, int grade_execute);

	// Getters
	int getGrade_sign() const;
	int getGrade_execute() const;
	std::string getName() const;
	bool getSign() const;

	// Member functions
	void beSigned(Bureaucrat& b);
	virtual void execute(Bureaucrat const & executor) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};
std::ostream &	operator<<(std::ostream & o, AForm  &rSym);


#endif