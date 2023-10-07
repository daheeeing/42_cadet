#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	targetName;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string targetName);
		PresidentialPardonForm(const PresidentialPardonForm &Pref);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &Pref);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};

#endif