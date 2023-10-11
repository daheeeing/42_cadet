#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string targetName;
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string targetName);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &Rref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &Rref);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;

};

#endif