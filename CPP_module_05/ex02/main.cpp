#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {	
        Bureaucrat b("Bureaucrat1", 24);
        ShrubberyCreationForm c("SS"); // s: 145, e: 137
        RobotomyRequestForm d("RR"); // 72, 45
        PresidentialPardonForm e("PP"); // 25, 5

        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << d << std::endl;
        std::cout << e << std::endl;
        std::cout << std::endl;
        
        b.signForm(c);
        b.signForm(d);
        b.signForm(e);	
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << d << std::endl;
        std::cout << e << std::endl;
        std::cout << std::endl;

        b.executeForm(c);
        std::cout << std::endl;
        b.executeForm(d);
        std::cout << std::endl;
        b.executeForm(e);
    }
    catch(std::exception &err)
    {
        std::cerr << err.what() << std::endl;
    }
	return (0);
}
