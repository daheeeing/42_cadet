#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat a("Tom", 51);
        Form f("form1", false, 50, 50);

		std::cout << a << std::endl;
		std::cout << f << std::endl;
		
        a.signForm(f);
		std::cout << a << std::endl;
		std::cout << std::endl;
		a.incrementBureaucratGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}