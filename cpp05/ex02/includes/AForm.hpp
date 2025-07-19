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
	
	AForm(); 
	AForm(const AForm& other); 
	AForm& operator=(const AForm& other); 
	virtual ~AForm();

	
	AForm(std::string name, int grade_sign, int grade_execute);

	int getGrade_sign() const;
	int getGrade_execute() const;
	std::string getName() const;
	bool getSign() const;

	void beSigned(Bureaucrat& b);
	virtual void execute(Bureaucrat const & executor) const = 0;

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