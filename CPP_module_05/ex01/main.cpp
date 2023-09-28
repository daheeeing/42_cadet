#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		//Bureaucrat b("dapark", 1);
		Bureaucrat b("dapark", 3);
		Form f("Form", 1, 2);
		//Form f("Form", 0, 2);
		//Form("Form", 2, 2);

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		f.beSigned(b);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}