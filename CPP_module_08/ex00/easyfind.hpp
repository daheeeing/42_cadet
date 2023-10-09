#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &con, int num)
{
	typename T::iterator iter;
	iter = std::find(con.begin(), con.end(), num);
	if (iter == con.end())
		throw std::runtime_error("The value isn't here!");
	return (iter);
}

#endif