#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &ref)
{
    this->type = ref.type;
    std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat &ref)
{
    if (this != &ref)
        this->type = ref.type;
    std::cout << "Cat copy assignment operator" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meow~~~~" << std::endl;
}
