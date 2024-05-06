/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:51 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 09:44:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP

# define ITERATORS_HPP

#include <iterator>

template<typename Iterator>
Iterator& advanceIterator(Iterator& it, int n);

template<typename RandomAccessIterator>
RandomAccessIterator& advanceIterator(RandomAccessIterator& it, int n, std::random_access_iterator_tag)
{
    it += n;
	return (it);
}

template<typename BidirectionalIterator>
BidirectionalIterator& advanceIterator(BidirectionalIterator& it, int n, std::bidirectional_iterator_tag)
{
    if (n > 0)
	{
        while (n--)
			++it;
    }
	else
	{
        while (n++)
			--it;
    }
	return (it);
}

template<typename ForwardIterator>
ForwardIterator& advanceIterator(ForwardIterator& it, int n, std::forward_iterator_tag)
{
    while (n--)
		++it;
	return (it);
}

// Definition of the primary function template
template<typename Iterator>
Iterator& advanceIterator(Iterator& it, int n)
{
    typename std::iterator_traits<Iterator>::iterator_category category;
    return (advanceIterator(it, n, category));
}



#endif
