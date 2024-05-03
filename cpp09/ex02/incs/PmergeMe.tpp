/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:33:42 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 10:05:51 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP

# define PMERGEME_TPP

#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <set>

#include <string>

//sequence
#include <vector>
#include <deque>
#include <list>


//inform template about the holder class
template <
	typename T,
	template <
		typename,
		typename
	> class First,
	template <
		typename,
		typename
	> class Second
> class	MergeInsertComp;


// Constructor
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> PmergeMe<T, Container, Allocator>::PmergeMe(
            const std::string (&g_type_info)[4],
			const std::string (&g_type_name)[4]) :
					_g_type_info(g_type_info),
					_g_type_name(g_type_name),
					_name_container(searchContainerName())
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Default Constructor Called" << std::endl;
    #endif
};

// Destructor
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> PmergeMe<T, Container, Allocator>::~PmergeMe()
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Destructor Called" << std::endl;
    #endif
};


//Copy Constructor and Assignment - private




template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> PmergeMe<T, Container, Allocator>::PmergeMe(const PmergeMe& copy)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Copy constructor Called" << std::endl;
    #endif
    (void)copy;
};


template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> PmergeMe<T, Container, Allocator>& PmergeMe<T, Container, Allocator>::operator=(const PmergeMe& assign)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Assignment Called" << std::endl;
    #endif
    (void)assign;
    return (*this);
}

#endif