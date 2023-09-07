#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// void    le()
// {
//     system("leaks ex02");
// }

int main()
{
    //atexit(le);

	//Animal animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	return (0);
}
