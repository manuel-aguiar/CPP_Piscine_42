/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuickSort.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:28:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 12:16:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_TPP

# define QUICKSORT_TPP

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	QuickSort(Container<T, Alloc>& container);

#endif
