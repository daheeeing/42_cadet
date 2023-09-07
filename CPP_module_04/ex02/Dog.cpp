#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
	std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &ref)
{
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain(*ref.brain);
    std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog &ref)
{
    if (this != &ref)
    {
        this->type = ref.type;
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    std::cout << "Dog copy assignment operator" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "bark!!!!" << std::endl;
}

Brain&	Dog::getBrain() const
{
    return (*this->brain);
}
