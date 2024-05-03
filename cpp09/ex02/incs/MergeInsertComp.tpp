/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:34:51 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 09:47:23 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MERGEINSERTCOMP_TPP

# define MERGEINSERTCOMP_TPP

# include "PmergeMe.hpp"

# include <algorithm>
# include <sstream>
# include <cerrno>
# include <limits>
# include <cstdio>

//constructor and driver
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
> MergeInsertComp<T, First, Second>::MergeInsertComp(int ac, char **av) :
    _count(ac),
    _first(g_type_info, g_type_name),
    _second(g_type_info, g_type_name)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "MergeInsertComp Constructor Called" << std::endl;
    #endif
    if (!parse(ac, av))
    {
        CERR("Error");
        return ;
    }
    _first.sort(_unsorted);
    _second.sort(_unsorted);
};

//Destructor

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
> MergeInsertComp<T, First, Second>::~MergeInsertComp()
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "MergeInsertComp Destructor Called" << std::endl;
    #endif
};

//Copy constructor - private

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
> MergeInsertComp<T, First, Second>::MergeInsertComp(const MergeInsertComp& copy)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "MergeInsertComp Copy Constructor Called" << std::endl;
    #endif
    (void)copy;
};

//Assignment operator - private

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
> MergeInsertComp<T, First, Second>& MergeInsertComp<T, First, Second>::operator=(const MergeInsertComp& assign)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "MergeInsertComp Assignment Called" << std::endl;
    #endif
    (void)assign; return (*this);
};

#endif