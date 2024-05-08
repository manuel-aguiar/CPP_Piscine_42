/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuickSort.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:28:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 12:30:43 by codespace        ###   ########.fr       */
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





static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int arr[], int low, int high, int (*cmp)(int, int))
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		i++;
		while (cmp(pivot, arr[i]))
			i++;
		j--;
		while (cmp(arr[j], pivot))
			j--;
		if (i >= j)
			return (j);
		swap(&arr[i], &arr[j]);
	}
}

static void	qs_recursion(int *arr, int low, int high, int (*cmp)(int, int))
{
	int	randpivot;
	int	part;

	if (low < high)
	{
		randpivot = low;
		swap(&arr[low], &arr[randpivot]);
		part = partition(arr, low, high, cmp);
		qs_recursion(arr, low, part, cmp);
		qs_recursion(arr, part + 1, high, cmp);
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
	qs_recursion(arr, 0, size - 1, cmp);
	return (arr);
}


#endif
