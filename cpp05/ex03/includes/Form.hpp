#ifndef FORM_HPP
#define FORM_HPP
// #pragma once
#include <iostream>
#include <string>
// #include "Bureaucrat.hpp"
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
    virtual ~Form();
    int getGrade_sign() ;
    int getGrade_execute() const ;
    std::string getName() const ;
    bool getSign() ;
    void beSigned(Bureaucrat& b);


    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException: std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException: std::exception {
		public:
			const char *what() const throw();
	};
    
};

std::ostream &	operator<<(std::ostream & o, Form  &rSym);


#endif