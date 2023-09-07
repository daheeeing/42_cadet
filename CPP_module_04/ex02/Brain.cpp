#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
	for (int i=0; i < 100; i++)
		ideas[i] = "BrainIdea";
}

Brain::Brain(const Brain &ref)
{
    std::cout << "Brain copy constructor" << std::endl;
	for (int i=0; i < 100; i++)
		ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain &ref)
{
    std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &ref)
	{
		for (int i=0; i < 100; i++)
			this->ideas[i] = ref.ideas[i];		
	}
	return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}

std::string Brain::getIdea(int i)
{
    return (ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
    if (i >= 0 && i < 100)
        this->ideas[i] = idea;
    else
        std::cout << "BrainIdea's size is 100 !!" << std::endl;
}
