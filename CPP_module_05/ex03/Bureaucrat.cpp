#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
    :name("default"), grade(1)
{}

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
{}

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

void Bureaucrat::signForm(AForm &formRef)
{
    try {
        bool chk;

        formRef.beSigned(*this);
        chk = formRef.getSigned();
        if (chk == true)
            std::cout << this->getName() << " signed " <<  formRef.getName() << std::endl;
    } catch(std::exception &err) {
        std::cerr << this->getName() << " couldn't sign " <<  formRef.getName() << " because the grade is too low." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    if (form.getSigned() == false)
	{
		std::cerr << this->name << " couldn’t execute " << form.getName() << ". ";
		throw AForm::IsNotSignedException();
	}
	if (grade > form.getExecGrade())
	{
		std::cerr << this->name << " couldn’t execute " << form.getName() << ". ";
		throw GradeTooLowException();	
	}
	form.execute(*this);
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
