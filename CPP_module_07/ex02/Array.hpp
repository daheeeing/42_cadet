#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T 		*arr;
		size_t	length;
    public:
        Array();
		Array(unsigned int n);
		Array(const Array &ref);
		Array& operator=(const Array &ref);
		~Array();
        T& operator[](size_t i);
        size_t size() const;
};

template <typename T>
Array<T>::Array()
    :length(0)
{
	arr = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
    :length(n)
{
	arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &ref)
    :length(ref.length)
{
	arr = new T[length];
	for (size_t i = 0; i < length; i++)
		arr[i] = ref.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &ref)
{
	if (this != &ref)
	{
		delete []arr;
		length = ref.length;
		arr = new T[length];
		for (size_t i = 0; i < length; i++)
			arr[i] = ref.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
}

template <typename T>
T& Array<T>::operator[](size_t i)
{
	if (i >= 0 && i < length)
		return (arr[i]);
	else
		throw std::out_of_range("out of bounds!!");
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->length);
}

#endif