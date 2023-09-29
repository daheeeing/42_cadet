#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	targetName;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string targetName);
		ShrubberyCreationForm(const ShrubberyCreationForm &Sref);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &Sref);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};

#endif