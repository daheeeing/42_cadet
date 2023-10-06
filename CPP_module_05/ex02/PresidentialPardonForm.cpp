#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    :AForm("P_Form", 25, 5), targetName("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string targetName)
    :AForm("P_Form", 25, 5), targetName(targetName)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Pref)
    :AForm(Pref.getName(), Pref.getSignGrade(), Pref.getExecGrade()), targetName(Pref.targetName)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &Pref)
{
    if (this != &Pref)
    {
        targetName = Pref.targetName;
        setName(Pref.getName());
        setExecGrade(Pref.getExecGrade());
        setSignGrade(Pref.getSignGrade());
        setSign(Pref.getSigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << targetName << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
