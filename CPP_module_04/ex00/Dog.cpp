#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &ref)
{
    this->type = ref.type;
    std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog &ref)
{
    if (this != &ref)
        this->type = ref.type;
    std::cout << "Dog copy assignment operator" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "bark!!!!" << std::endl;
}
