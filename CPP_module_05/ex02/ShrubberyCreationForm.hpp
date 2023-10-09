#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	targetName;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string targetName);
		ShrubberyCreationForm(const ShrubberyCreationForm &Sref);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &Sref);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};

#endif