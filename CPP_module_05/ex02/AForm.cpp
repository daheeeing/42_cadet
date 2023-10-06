#include "AForm.hpp"

AForm::AForm()
    :name("default"), sign(false), signGrade(1), execGrade(1)
{}

AForm::AForm(std::string name, int signGrade, int execGrade)
    :name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &ref)
    :name(ref.name), sign(ref.sign), signGrade(ref.signGrade), execGrade(ref.execGrade)
{}

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

bool AForm::getSigned() const
{
    return (this->sign);
}

const std::string& AForm::getName() const
{
    return (this->name);
}

const int& AForm::getSignGrade() const
{
    return (this->signGrade);
}

const int& AForm::getExecGrade() const
{
    return (this->execGrade);
}

void AForm::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() <= this->getSignGrade())
        this->sign = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
}

void	AForm::setName(const std::string &name)
{
    const_cast<std::string&>(this->name) = name;
}

void	AForm::setSign(bool sign)
{
    this->sign = sign;
}

void	AForm::setSignGrade(int signGrade)
{
    const_cast<int&>(this->signGrade) = signGrade;
}

void	AForm::setExecGrade(int execGrade)
{
    const_cast<int&>(this->execGrade) = execGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low.";
}

const char* AForm::IsNotSignedException::what() const throw()
{
    return "This form is not signed.";
}

std::ostream& operator<<(std::ostream &out, const AForm &ref)
{
    out << ref.getName() << std::boolalpha << ", signed : " << ref.getSigned() << ", signed grade : " << ref.getSignGrade() << ", execute grade : " << ref.getExecGrade();
	return (out);
}
