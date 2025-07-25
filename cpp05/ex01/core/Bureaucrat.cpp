#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
// Bureaucrat::Bureaucrat()
// {
//     std::cout << "constrcutor is initialized" << std::endl;
// }

Bureaucrat::Bureaucrat(std::string name,int grade) : name(name) , grade(grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destroy of"<< name << " is initialized" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat& other) {
	if  (this != &other) 
		this->grade = other.grade;
	return *this;
}   
std::string Bureaucrat::getName(){
    return name;
}

int Bureaucrat::getGrade(){
    return grade;
}

void Bureaucrat::incrementGrade(){
    if (grade - 1 < min_grade)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade(){
    if (grade + 1 > max_grade)
        throw GradeTooLowException();
    ++grade;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat  &rSym){
   o << rSym.getName() << ", bureaucrat grade " << rSym.getGrade() << ".\n";
    return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!\n";
}


void Bureaucrat::signForm(Form& f){
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}
