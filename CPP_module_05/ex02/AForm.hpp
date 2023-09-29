#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;
	
    protected:
		void	setName(const std::string &name);
		void	setSign(bool sign);
		void	setSignGrade(int signGrade);
		void	setExecGrade(int execGrade);
	
    public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &ref);
		AForm& operator=(const AForm &ref);
		virtual ~AForm();
		bool getSigned() const;
		const std::string& getName() const;
		const int& getSignGrade() const;
		const int& getExecGrade() const;
		void beSigned(const Bureaucrat& bur);
		virtual void execute(Bureaucrat const & executor) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class IsNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif