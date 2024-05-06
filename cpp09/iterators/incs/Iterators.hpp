/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:51 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 09:32:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP

# define ITERATORS_HPP

#include <iterator>

template<typename Iterator>
void advanceIterator(Iterator& it, int n);

template<typename RandomAccessIterator>
void advanceIterator(RandomAccessIterator& it, int n, std::random_access_iterator_tag) {
    it += n;
}

template<typename BidirectionalIterator>
void advanceIterator(BidirectionalIterator& it, int n, std::bidirectional_iterator_tag) {
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
}

template<typename ForwardIterator>
void advanceIterator(ForwardIterator& it, int n, std::forward_iterator_tag)
{
    while (n--)
		++it;
}

// Definition of the primary function template
template<typename Iterator>
void advanceIterator(Iterator& it, int n)
{
    typename std::iterator_traits<Iterator>::iterator_category category;
    advanceIterator(it, n, category);
}



#endif
