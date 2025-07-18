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
    Form(std::string name, int grade_sign, int grade_execute);
    ~Form();
    int getGrade_sign() const;
int getGrade_excute() const;
std::string getName() const;
bool getSign() const;
    void beSigned(Bureaucrat& b);

    class GradeTooHighException: std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException: std::exception {
		public:
			const char *what() const throw();
	};
    
};

std::ostream&	operator<<(std::ostream & o, Form  &rSym);


#endif