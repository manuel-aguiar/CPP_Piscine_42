/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterFuncs.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:05:46 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 11:08:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERFUNCS_TPP

# define ITERFUNCS_TPP

#include <iterator>



template <
	typename Iterator
>
Iterator	next(Iterator& iter, int index)
{
	typename std::iterator_traits<Iterator>::iterator_category category;
	Iterator copy(iter);
	copy = advanceeee(copy, index, category);
	return (copy);
}

template <
	typename Iterator
>
Iterator	prev(Iterator& iter, int index)
{
	typename std::iterator_traits<Iterator>::iterator_category category;
	Iterator copy(iter);
	copy = advanceeee(copy, -index, category);
	return (copy);
}

template <
	typename Iterator
>
Iterator& advanceeee(Iterator& iter, int n)
{
	typename std::iterator_traits<Iterator>::iterator_category category;
	return (advanceeee(iter, n, category));
}

template <
	typename Iterator
>
Iterator& advanceeee(Iterator& iter, int n, std::random_access_iterator_tag)
{
	iter += n;
	return (*iter);
}

template <
	typename Iterator
>
Iterator& advanceeee(Iterator& iter, int n, std::bidirectional_iterator_tag)
{
	if (n > 0)
	{
		while (n--)
			++iter;
	}
	else
	{
		while (n++)
			--iter;
	}
	return (iter);
}

template <
	typename Iterator
>
Iterator& advanceeee(Iterator& iter, int n, std::forward_iterator_tag)
{
	while (n--)
		++iter;
	return (iter);
}



#endif
