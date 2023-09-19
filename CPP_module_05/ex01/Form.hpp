#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private :
	    const std::string   name;
        bool                sign;
	    const int           signGrade;
        const int           execGrade;

    public :
        Form();
        Form(std::string name, bool sign, const int signGrade, const int execGrade);
        Form(const Form &ref);
        Form& operator=(const Form &ref);
        ~Form();
        const std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSigned() const; 
        void beSigned(Bureaucrat &bur);
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

std::ostream& operator<<(std::ostream &out, const Form &b);

#endif
