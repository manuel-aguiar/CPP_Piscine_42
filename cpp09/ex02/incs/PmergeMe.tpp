/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:33:42 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 10:53:13 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP

# define PMERGEME_TPP

#include <algorithm>
#include <typeinfo>
#include <iostream>

#include <string>

//sequence
#include <vector>
#include <deque>
#include <list>


//helper function 
void	print_num(const unsigned int num);

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
					_name_container(deduceContainerName())
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


//deduce container name

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> 
const std::string&		PmergeMe<T, Container, Allocator>::deduceContainerName(void)
{
    int i = 0;
    std::string myType = typeid(_numbers).name();
    while (i < 3)
    {
        if (myType == _g_type_info[i])
            return (_g_type_name[i]);
        i++;
    }
    return (_g_type_name[i]);
}

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> 
void		PmergeMe<T, Container, Allocator>::dumpUnsorted(const std::vector<unsigned int>& unsorted)
{
    _numbers.insert(_numbers.end(), unsorted.begin(), unsorted.end());
}

//Sort member function
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> 
void		PmergeMe<T, Container, Allocator>::sort(const std::vector<unsigned int>& unsorted)
{
    dumpUnsorted(unsorted);
    printNumbers();
}


template <
    typename T,
    template <
        typename,
        typename
    > class Container,
    typename Allocator
> 
void		PmergeMe<T, Container, Allocator>::printNumbers(void) const
{
    std::cout << "Container - " << _name_container << " - numbers: ";
    std::for_each(_numbers.begin(), _numbers.end(), print_num);
    std::cout << std::endl;
}

#endif