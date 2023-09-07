#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void le()
// {
//     system("leaks ex01");
// }

int main()
{
    //atexit(le);

    const Animal* meta[4];
    meta[0] = new Dog();
    meta[1] = new Dog();
    meta[2] = new Cat();
    meta[3] = new Cat();
    std::cout << std::endl;
    for(int i = 0; i < 4; i++)
        delete meta[i];
    std::cout << std::endl;

    std::cout << "---------- DeepCopy testcase ----------" << std::endl;
    std::cout << std::endl;
    Dog d2;
    Dog d1 = d2; // 복사 생성자 deep copy
    std::cout << std::endl;
    std::cout << "d1 : " << d1.getBrain().getIdea(5) << std::endl; 
    std::cout << "d2 : " << d2.getBrain().getIdea(5) << std::endl;
    std::cout << std::endl;
    d1.getBrain().setIdea(5, "this is new!");
    std::cout << "d1 : " << d1.getBrain().getIdea(5) << std::endl; 
    std::cout << "d2 : " << d2.getBrain().getIdea(5) << std::endl;
    std::cout << std::endl;

    Dog d3;
    Dog d4;
    d3 = d4; // 대입 연산자 오버로딩 deep copy
    std::cout << std::endl;
    std::cout << "d3 : " << d3.getBrain().getIdea(5) << std::endl; 
    std::cout << "d4 : " << d4.getBrain().getIdea(5) << std::endl;
    std::cout << std::endl;
    d3.getBrain().setIdea(5, "this is new!");
    std::cout << "d3 : " << d3.getBrain().getIdea(5) << std::endl; 
    std::cout << "d4 : " << d4.getBrain().getIdea(5) << std::endl;
    std::cout << std::endl;
    return (0);
}
