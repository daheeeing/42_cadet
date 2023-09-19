#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
    :name("default"), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
    :name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
    :name(ref.name), grade(ref.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
    if (this != &ref)
    {
        const_cast<std::string&>(name) = ref.getName();
        grade = ref.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::incrementBureaucratGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementBureaucratGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::signForm(Form &formRef)
{
    bool chk;

    chk = formRef.getSigned();
    if (chk == true)
        std::cout << this->getName() << " signed " <<  formRef.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " <<  formRef.getName() << " because the grade is too low." << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (out);
}
