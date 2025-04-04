#include "../includes/Form.hpp"

Form::Form(std::string name,int grade_sign,int grade_execute): name(name), grade_sign(grade_sign), grade_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw GradeTooLowException();
    }
}


Form::~Form()
{
}
