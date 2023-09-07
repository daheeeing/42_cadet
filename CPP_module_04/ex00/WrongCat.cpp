#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	this->type = ref.type;
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &ref)
{
	if (this != &ref)
		this->type = ref.type;
    std::cout << "WrongCat copy assignment operator" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "meow~~~~" << std::endl;
}
