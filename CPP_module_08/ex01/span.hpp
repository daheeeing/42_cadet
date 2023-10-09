#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>


class Span
{
    private:
        std::vector<int>	vec;
		unsigned int		num_val;

    public:
        Span();
        Span(const unsigned int num);
        Span(const Span& ref);
        Span& operator=(const Span& ref);
        ~Span();
        size_t longestSpan();
	    size_t shortestSpan();
        void addNumber(const int num);
        void addMoreNumber();
        int getNumber(size_t num);
};

#endif