#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form()
    : name("DefaultForm"), is_signed(false), grade_sign(150), grade_execute(150)
{
    std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, int grade_sign, int grade_execute) : name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
    {
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150)
    {
        throw GradeTooLowException();
    }
}

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed),
      grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "destructor is called" << std::endl;
}

int Form::getGrade_sign() const
{
    return grade_sign;
}
int Form::getGrade_excute() const
{
    return grade_execute;
}
std::string Form::getName() const
{
    return name;
}
bool Form::getSign() const
{
    return is_signed;
}
void Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() > grade_sign)
        throw GradeTooLowException();
    is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too Low!\n";
}

std::ostream &operator<<(std::ostream &o, Form &rsym)
{
    o << rsym.getName() << ", form grade sign: " << rsym.getGrade_sign()
      << ", grade execute: " << rsym.getGrade_excute()
      << ", signed: " << (rsym.getSign() ? "yes" : "no") << "." << std::endl;
    return o;
}