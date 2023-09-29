#include "AForm.hpp"

AForm::AForm()
    :name("default"), sign(false), signGrade(1), execGrade(1)
{}

AForm::AForm(std::string name, int signGrade, int execGrade)
    :name(name), signGrade(signGrade), execGrade(execGrade)
{}

AForm::AForm(const AForm &ref)
{

}

AForm& AForm::operator=(const AForm &ref)
{
    if (this != &ref)
	{
		const_cast<std::string&>(name) = ref.getName();
		sign = ref.getSigned();
		const_cast<int&>(signGrade) = ref.getSignGrade();
		const_cast<int&>(execGrade) = ref.getExecGrade();
	}
	return (*this);
}

AForm::~AForm() {}

bool AForm::getSigned() const;
{
    return (this->signed);
}

const std::string& AForm::getName() const;
{
    return (this->name);
}

const int& AForm::getSignGrade() const;
{
    return (this->signGrade);
}

const int& AForm::getExecGrade() const;
{
    return (this->execGrade);
}

void AForm::beSigned(const Bureaucrat& bur)
{

}

void AForm::execute(Bureaucrat const & executor) const
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade too low.";
}

const char* AForm::IsNotSignedException::what() const throw()
{
    return "This form is not signed.";
}

std::ostream& operator<<(std::ostream &out, const AForm &f)
{

}
