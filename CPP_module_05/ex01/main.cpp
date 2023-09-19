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
		a.incrementBureaucratGrade();
		std::cout << a << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}