#include "Form.hpp"

Form::Form()
    :name("default"), sign(false), signGrade(150), execGrade(150)
{}

Form::Form(std::string name, const int signGrade, const int execGrade)
    :name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &ref)
    :name(ref.name), sign(ref.sign), signGrade(ref.signGrade), execGrade(ref.execGrade)
{}

Form& Form::operator=(const Form &ref)
{
    if (this != &ref)
    {
        const_cast<std::string&>(name) = ref.getName();
        const_cast<int&>(signGrade) = ref.getSignGrade();
        const_cast<int&>(execGrade) = ref.getExecGrade();
        sign = ref.getSigned();
    }
    return (*this);
}
        
Form::~Form() {}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getExecGrade() const
{
    return (this->execGrade);
}

bool Form::getSigned() const
{
    return (this->sign);
}

void Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= this->signGrade)
        this->sign = true;
    else
        throw GradeTooLowException();
}
        
const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &out, const Form &ref)
{
	out << ref.getName() << std::boolalpha << ", signed : " << ref.getSigned() << ", signed grade : " << ref.getSignGrade() << ", execute grade : " << ref.getExecGrade();
	return (out);
}
