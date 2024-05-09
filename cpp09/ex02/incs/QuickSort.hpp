/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuickSort.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:47 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 12:15:50 by codespace        ###   ########.fr       */
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

#include "../tpp/QuickSort.tpp"



#endif
