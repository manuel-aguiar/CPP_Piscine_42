/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:23:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/17 09:43:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <class Container>
typename Container::iterator
easyfind(Container& container, int value)
{
	typename Container::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cerr << "ops"<< std::endl;
    return (it);
}

template <template<typename, typename, typename, typename> class Container,
	typename Value, typename Compare, typename Allocator>
typename Container<int, Value, Compare, Allocator>::iterator
easyfind(Container<int, Value, Compare, Allocator>& container, int key)
{
	typename Container<int, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		std::cerr << "ops"<< std::endl;
    return (it);
}

template <template<typename, typename, typename, typename> class Container,
	typename Key, typename Value, typename Compare, typename Allocator>
typename Container<Key, Value, Compare, Allocator>::iterator
generic_easyfind(Container<Key, Value, Compare, Allocator>& container, Key& key)
{
	typename Container<Key, Value, Compare, Allocator>::iterator it = container.find(key);
	if (it == container.end())
		std::cerr << "ops"<< std::endl;
    return (it);
}

template <class Container, typename Value>
typename Container::iterator
generic_easyfind(Container& container, Value& value)
{
	typename Container::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cerr << "ops"<< std::endl;
    return (it);
}

/*
	container.end() is a sentinel value that is one past the last value in the container
	therefore it is not an element placed by the user and essentially means that
	a value is not found when this sentinel is the only left
*/



#endif
