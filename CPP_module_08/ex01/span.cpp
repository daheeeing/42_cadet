#include "span.hpp"

Span::Span()
    :num_val(0)
{}

Span::Span(const unsigned int num)
    :num_val(num)
{}

Span::Span(const Span& ref)
    :vec(ref.vec), num_val(ref.num_val)
{}

Span& Span::operator=(const Span& ref)
{
    if (this != &ref)
	{
		num_val = ref.num_val;
		vec = ref.vec;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(const int num)
{
    if (num_val == vec.size())
        throw std::out_of_range("out of range!!");
    vec.push_back(num);
}

size_t Span::longestSpan()
{
    if (num_val < 2)
		throw std::runtime_error("more numbers are needed");
    size_t longest;
    std::sort(vec.begin(), vec.end());
    longest = static_cast<size_t>(*(vec.end()-1) - *vec.begin());
    return (longest);
}

size_t Span::shortestSpan()
{
    if (num_val < 2)
		throw std::runtime_error("more numbers are needed");
    size_t shortest, tmp;
    std::sort(vec.begin(), vec.end());
    for (unsigned int i=0; i < num_val-1 ; i++)
    {
        tmp = static_cast<size_t>(*(vec.begin()+(i+1)) - *(vec.begin()+i));
        if (i == 0)
            shortest = tmp;
        if (tmp < shortest)
            shortest = tmp;
    }
    return (shortest);
}

void Span::addMoreNumber()
{
    if (num_val == vec.size())
        throw std::out_of_range("out of range!!");
    for(unsigned int i=0; i < num_val; i++)
    {
        size_t num = vec.size();
        vec.push_back(num);   
    }
}
