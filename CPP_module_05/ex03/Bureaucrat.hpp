#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
    private :
	    const std::string   name;
	    int                 grade;

    public :
        Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat& operator=(const Bureaucrat &ref);
		~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void incrementBureaucratGrade();
        void decrementBureaucratGrade();
		void signForm(AForm &formRef);
		void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception
	    {
		    public:
		        const char * what(void) const throw();
	    };
	    class GradeTooLowException : public std::exception
	    {
		    public:
		        const char * what(void) const throw();
	    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
