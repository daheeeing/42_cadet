#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string targetName;
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string targetName);
		RobotomyRequestForm(const RobotomyRequestForm &Rref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &Rref);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;

};

#endif