#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *A, size_t length, void (*func)(T))
{
    size_t i;
    for(i = 0; i < length ; i++)
        func(A[i]);
    return ;
}

template <typename T>
void printA(T input)
{
    std::cout << input << std::endl;
    return ;
}

#endif