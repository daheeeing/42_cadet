#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    :type("None")
{
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	this->type = ref.type;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (this != &ref)
		this->type = ref.type;
    std::cout << "WrongAnimal copy assignment operator" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "No sound" << std::endl;
}
