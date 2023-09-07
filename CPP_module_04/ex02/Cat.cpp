#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &ref)
{
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain(*ref.brain);
    std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat &ref)
{
    if (this != &ref)
    {
        this->type = ref.type;
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    std::cout << "Cat copy assignment operator" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meow~~~~" << std::endl;
}

Brain&	Cat::getBrain() const
{
    return (*this->brain);
}
