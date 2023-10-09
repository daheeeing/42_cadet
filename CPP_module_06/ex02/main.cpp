#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    srand(static_cast<unsigned int>(std::time(NULL)));
    int chk = rand()%3;
    if (chk == 0)
        return (new A);
    else if (chk == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "* : A class" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "* : B class" << std::endl;
    else
        std::cout << "* : C class" << std::endl;
}

void identify(Base& p)
{
    try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "& : A Class" << std::endl;
		(void)a;
	}
	catch(const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "& : B Class" << std::endl;
		(void)b;
	}
	catch(const std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "& : C Class" << std::endl;
		(void)c;
	}
	catch(const std::exception& e){}
}

int main()
{
	Base base;

	Base *test1 = generate();
    Base *test2 = generate();
	identify(*test1);
    identify(*test2);
	identify(test1);
	identify(test2);
	
	delete (test1);
    delete (test2);
	return (0);
}
