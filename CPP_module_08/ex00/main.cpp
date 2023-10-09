#include "easyfind.hpp"
#include <vector>

int main()
{
    try {
    std::vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	std::cout << *(easyfind(v, 2)) << std::endl;
	std::cout << *(easyfind(v, 4)) << std::endl;
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}