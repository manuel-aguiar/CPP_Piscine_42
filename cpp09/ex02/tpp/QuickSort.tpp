/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuickSort.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:28:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 13:26:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_TPP

# define QUICKSORT_TPP

# include "IterFuncs.hpp"

# include <algorithm>
# include <iomanip>

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	QuickSort(Container<T, Alloc>& container);

template <
	class T
>
static bool qs_compare(T& a, T& b, size_t& g_comp_count)
{
	g_comp_count++;
	return (a == b);
}

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
typename Container<T, Alloc>::iterator	qs_partition(typename Container<T, Alloc>::iterator low,
													typename Container<T, Alloc>::iterator high,
													size_t& g_comp_count)
{
	T										pivot;
	typename Container<T, Alloc>::iterator	i;
	typename Container<T, Alloc>::iterator	j;

	pivot = *low;
	i = next(low, -1);
	j = next(high, 1);
	while (1)
	{
		i++;
		while (qs_compare(pivot, *i, g_comp_count))
			i++;
		j--;
		while (qs_compare(*j, pivot, g_comp_count))
			j--;
		if (std::distance(i, j) <= 0)
			return (j);
		std::swap(*i, *j);
	}
}

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
static void	qs_recursion(typename Container<T, Alloc>::iterator low,
						typename Container<T, Alloc>::iterator high,
						size_t& g_comp_count)
{
	typename Container<T, Alloc>::iterator	part;

	if (std::distance(low, high) > 0)
	{
		part = qs_partition<Container, T, Alloc>(low, high, g_comp_count);
		qs_recursion<Container, T, Alloc>(low, part, g_comp_count);
		qs_recursion<Container, T, Alloc>(next(part, 1), high, g_comp_count);
	}
}

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	QuickSort(Container<T, Alloc>& container)
{
	size_t g_comp_count = 0;

	typedef typename Container<T, Alloc>::iterator iterator;

	iterator begin = container.begin();
	iterator end = container.end();

	qs_recursion<Container, T, Alloc>(
		begin,
		end,
		g_comp_count
	);

	return (g_comp_count);
}


#endif
