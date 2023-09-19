#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		
		// a.decrementGrade();
	
		// b.incrementGrade();
	
		//std::cout << a << std::endl;
		//std::cout << b << std::endl;
		//std::cout << std::endl;

		a.incrementBureaucratGrade();
		b.decrementBureaucratGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
