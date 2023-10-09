#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :AForm("R_Form", 72, 45), targetName("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string targetName)
    :AForm("R_Form", 72, 45), targetName(targetName)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Rref)
    :AForm(Rref.getName(), Rref.getSignGrade(), Rref.getExecGrade()), targetName(Rref.targetName)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target)
    :AForm(name, 72, 45), targetName(target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &Rref)
{
    if(this != &Rref)
    {   
        targetName = Rref.targetName;
        setName(Rref.getName());
        setExecGrade(Rref.getExecGrade());
        setSignGrade(Rref.getSignGrade());
        setSign(Rref.getSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int chk;
    srand(static_cast<unsigned int>(std::time(NULL)));
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::cout << "drilling noises....";
    chk = rand() % 2;
    if (chk == 0)
		std::cout << this->targetName << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->targetName << " has failed." << std::endl;
}
