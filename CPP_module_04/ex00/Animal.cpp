#include "Animal.hpp"

Animal::Animal()
    :type("None")
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	this->type = ref.type;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal &ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "Animal copy assignment operator" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "No sound" << std::endl;
}
