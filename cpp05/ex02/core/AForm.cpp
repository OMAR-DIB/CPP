#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// Default constructor
AForm::AForm()
	: name("DefaultForm"), is_signed(false), grade_sign(150), grade_execute(150)
{
	std::cout << "AForm default constructor called\n";
}

// Param constructor
AForm::AForm(std::string name, int grade_sign, int grade_execute)
	: name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
	: name(other.name),
	  is_signed(other.is_signed),
	  grade_sign(other.grade_sign),
	  grade_execute(other.grade_execute)
{
	std::cout << "AForm copy constructor called\n";
}
AForm& AForm::operator=(const AForm& other){
	if(this != &other){
		this->is_signed = other.is_signed;
	}
	 return (*this);
}
// Destructor
AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}


int AForm::getGrade_sign() const  {
    return grade_sign;
}

int AForm::getGrade_execute() const  {
    return  grade_execute;
}

std::string AForm::getName() const {
    return name;
}

bool AForm::getSign()  const {
    return is_signed;
}

void AForm::beSigned(Bureaucrat& bur){
    if (bur.getGrade() > grade_sign)
        throw GradeTooLowException();
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too Low!\n";
}

std::ostream & operator<<(std::ostream & o, AForm  &rsym){
    o << rsym.getName() << ", AForm grade sign :" << rsym.getGrade_sign() << ", AForm grade execute :" << rsym.getGrade_execute() <<",is AForm signed? :" << rsym.getSign() <<"\n";
    return o;
}