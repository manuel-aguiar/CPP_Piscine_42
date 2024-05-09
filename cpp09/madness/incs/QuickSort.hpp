/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuickSort.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 10:25:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_HPP

# define QUICKSORT_HPP

# include "IterFuncs.hpp"

# include <algorithm>
# include <iomanip>

/* quicksort, returns the total number of comparisons*/
template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	QuickSort(Container<T, Alloc>& container);

/* QuickSortFunctor functor class, just for fun*/

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
class QuickSortFunctor
{
	public:
		QuickSortFunctor() {};
		~QuickSortFunctor() {};
		QuickSortFunctor(const QuickSortFunctor& copy) {(void)copy;};
		QuickSortFunctor& operator=(const QuickSortFunctor& assign) {(void)assign; return(*this);};

		size_t operator()(Container<T, Alloc>& container)
			{return (QuickSortFunctorSort(container));}
};

#include "../tpp/QuickSort.tpp"



#endif
