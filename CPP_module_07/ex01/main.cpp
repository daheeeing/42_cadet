#include "iter.hpp"

int main()
{
    int intA[4] = {1, 2, 3, 4};
	char charA[7] = "dapark";

	::iter<int>(intA, 4, printA);
	std::cout << "-------" << std::endl;
	::iter<char>(charA, 6, printA);
	
    return (0);
}
