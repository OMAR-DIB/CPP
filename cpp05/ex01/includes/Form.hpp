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
	
	Form(); 
	Form(const Form& other); 
	Form& operator=(const Form& other);
	~Form();
	Form(std::string name, int grade_sign, int grade_execute);

	int getGrade_sign() const;
	int getGrade_excute() const;
	std::string getName() const;
	bool getSign() const;

	void beSigned(Bureaucrat &b);
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