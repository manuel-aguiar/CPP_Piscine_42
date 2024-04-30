/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:23:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 10:43:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

/*
	Removed the Allocator, it is deduced by the compiler anyways as std::allocator<int>
	less verbose
*/

template <
    template <
		typename
	> class Container
>
typename Container<int>::iterator
easyfind(const Container<int>& container, const int value)
{
	#ifdef CALL_TEMPLATE
    	std::cout << "calling easyfind, INTEGER, SEQUENCE containers" << std::endl;
	#endif
    typename Container<int>::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

/*
	Here deduction fails unless i pass the full template arguments of the container
	for the compiler to match

	The compiler will create the allocator for the vector given the sizeof(class V)

	When the type is <int>, the compiler knows the sizeof already and can create
	the required std::allocator and we can ommit that
*/

template <
    template<
		typename,
		typename
	> class C,
    typename V,
	typename Allocator
>
typename C<V, Allocator>::iterator
easyfind(C<V, Allocator>& container, const V& value)
{
	#ifdef CALL_TEMPLATE
    	std::cout << "calling easyfind, GENERIC, SEQUENCE containers" << std::endl;
	#endif
    typename C<V, Allocator>::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return (it);
}

/*
	Associative template with object types known to the compiler
	Less verbose template, same principle as the template<int>
	for the sequencial container
*/

template <
	template<
		typename,
		typename
	> class Container
>
typename Container<int, int>::iterator
easyfind(Container<int, int>& container, const int key)
{
	#ifdef CALL_TEMPLATE
		std::cout << "calling easyfind, INTEGER + INTEGER, ASSOCIATIVE containers" << std::endl;
	#endif
	typename Container<int, int>::iterator it = container.find(key);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

/*
	Associative template without known types to the compiler, require the super verbose stuff
*/

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
easyfind(Container<int, Value, Compare, Allocator>& container, const int key)
{
	#ifdef CALL_TEMPLATE
		std::cout << "calling easyfind, INTEGER + template class, ASSOCIATIVE containers" << std::endl;
	#endif
	typename Container<int, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

/*
	Associative template without known types to the compiler, require the super verbose stuff
*/

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
easyfind(Container<Key, Value, Compare, Allocator>& container, const Key& key)
{
	#ifdef CALL_TEMPLATE
		std::cout << "calling easyfind, GENERIC, ASSOCIATIVE containers" << std::endl;
	#endif
	typename Container<Key, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
    return (it);
}

/*
	Oh no, std::set requires its own template :(
*/

template <
	template<
		typename,
		typename,
		typename
	> class Container,
	typename Key,
	typename Compare,
	typename Allocator
>
typename Container<Key, Compare, Allocator>::iterator
easyfind(const Container<Key, Compare, Allocator>& container, const Key& key)
{
	#ifdef CALL_TEMPLATE
		std::cout << "calling easyfind, GENERIC, for std::set" << std::endl;
	#endif
	typename Container<Key, Compare, Allocator>::iterator it = container.find(key);
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
