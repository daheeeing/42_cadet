#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
    public:
        ~Base();
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif