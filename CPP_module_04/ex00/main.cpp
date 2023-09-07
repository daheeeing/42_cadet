#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void le()
// {
//     system("leaks ex00");
// }

int main()
{
    //atexit(le);

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
	delete j;
	delete i;
    std::cout << std::endl;

    std::cout << "---------- WrongAnimal and WrongCat testcase ----------" << std::endl;
    std::cout << std::endl;

    const WrongAnimal* wrongCase = new WrongCat();
    std::cout << wrongCase->getType() << " " << std::endl;
    wrongCase->makeSound();
    delete wrongCase;
    std::cout << std::endl;

    return (0);
}
