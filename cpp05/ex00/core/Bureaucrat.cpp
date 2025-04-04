#include "../includes/Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
{
    std::cout << "constrcutor is initialized" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name,int grade) : name(name) , grade(grade)
{
    std::cout << "constrcutor is initialized" << std::endl;
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
    this->grade--;
    if (grade < min_grade){
        throw GradeTooHighException();
    }
}
void Bureaucrat::decrementGrade(){
    this->grade++;
    if (grade < max_grade){
        throw GradeTooLowException();
    }
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat  &rSym){
   o << rSym.getName() << ", bureaucrat grade ." << rSym.getGrade() << "\n";
    return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!\n";
}