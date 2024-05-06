/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:51 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 14:03:01 by codespace        ###   ########.fr       */
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

template <
	typename Iterator
> class GroupIterator
{
	public:
		GroupIterator(Iterator it, size_t size) :
			_group_iter(it),
			_group_size(size)
		{};
		~GroupIterator() {};
		GroupIterator(const GroupIterator& copy) :
			_group_iter(copy._group_iter),
			_group_size(copy._group_size)
		{}
		GroupIterator& operator=(const GroupIterator& assign)
		{
			_group_iter = assign._group_iter;
			_group_size = assign._group_size;
			return (*this);
		}

        typedef typename std::iterator_traits<Iterator>::iterator_category 	iterator_category;
        typedef Iterator													iterator_type;
        typedef typename std::iterator_traits<Iterator>::value_type 		value_type;
        typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
        typedef typename std::iterator_traits<Iterator>::pointer 			pointer;
        typedef typename std::iterator_traits<Iterator>::reference  		reference;

		Iterator&	getIter(void) {return (_group_iter);};
		size_t		getSize(void) {return (_group_size);};

		//reference = value_type&
		reference operator*()
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (dereference_rightmost(category));
		}

		pointer operator->()
		{
			return (&operator*());
		}

		GroupIterator&	operator++(void)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (advanceIterator(1, category));
		}

		GroupIterator	operator++(int)
		{
			GroupIterator temp(*this);
			++(*this);
			return (temp);
		}

		GroupIterator&	operator--(void)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (advanceIterator(-1, category));
		}

		GroupIterator	operator--(int)
		{
			GroupIterator temp(*this);
			--(*this);
			return (temp);
		}

	private:

		Iterator	_group_iter;
		size_t		_group_size;

		GroupIterator() {};

		reference dereference_rightmost(std::random_access_iterator_tag)
		{
			return (_group_iter[_group_size - 1]);
		}

		reference dereference_rightmost(std::bidirectional_iterator_tag)
		{
			Iterator iter = _group_iter;
			for (size_t i = 0; i < _group_size - 1; ++i)
				iter++;
			return (*iter);
		}

		reference dereference_rightmost(std::forward_iterator_tag)
		{
			Iterator iter = _group_iter;
			for (size_t i = 0; i < _group_size - 1; ++i)
				iter++;
			return (*iter);
		}

		GroupIterator& advanceIterator(int n)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (advanceIterator(n, category));
		}

		GroupIterator& advanceIterator(int n, std::random_access_iterator_tag)
		{
			n *= _group_size;
			_group_iter += n;
			return (*this);
		}

		GroupIterator& advanceIterator(int n, std::bidirectional_iterator_tag)
		{
			n *= _group_size;
			if (n > 0)
			{
				while (n--)
					++_group_iter;
			}
			else
			{
				while (n++)
					--_group_iter;
			}
			return (*this);
		}

		GroupIterator& advanceIterator(int n, std::forward_iterator_tag)
		{
			n *= _group_size;
			while (n--)
				++_group_iter;
			return (*this);
		}
};


#endif
