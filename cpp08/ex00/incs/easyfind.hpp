/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:23:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/17 13:52:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

template <
	class Container
>
typename Container::iterator
easyfind(Container& container, int value)
{
	std::cout << "calling easyfind, INTEGER, SEQUENCE containers" << std::endl;
	typename Container::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

template <
	class Container,
	typename Value
>
typename Container::iterator
easyfind(Container& container, Value& value)
{
	std::cout << "calling easyfind, GENERIC, SEQUENCE containers" << std::endl;
	typename Container::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

template <
	template<
		typename,
		typename,
		typename,
		typename
	> class Container,
	typename Value,
	typename Compare,
	typename Allocator
>
typename Container<int, Value, Compare, Allocator>::iterator
easyfind(Container<int, Value, Compare, Allocator>& container, int key)
{
	std::cout << "calling easyfind, INTEGER, ASSOCIATIVE containers" << std::endl;
	typename Container<int, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

template <
	template<
		typename,
		typename,
		typename,
		typename
	> class Container,
	typename Key,
	typename Value,
	typename Compare,
	typename Allocator
>
typename Container<Key, Value, Compare, Allocator>::iterator
easyfind(Container<Key, Value, Compare, Allocator>& container, Key& key)
{
	std::cout << "calling easyfind, GENERIC, ASSOCIATIVE containers" << std::endl;
	typename Container<Key, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}



/*
	container.end() is a sentinel value that is one past the last value in the container
	therefore it is not an element placed by the user and essentially means that
	a value is not found when this sentinel is the only left
*/



#endif
