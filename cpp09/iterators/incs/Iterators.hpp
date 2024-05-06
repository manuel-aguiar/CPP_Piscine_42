/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:51 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 16:28:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP

# define ITERATORS_HPP

#include <iterator>
#include <iostream>

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
		Iterator	getRightmost(void)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (getRightmost(category));
		}
		Iterator	getLast(void)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (++getRightmost(category));
		}
		size_t		getSize(void) {return (_group_size);};

		//reference = value_type&
		reference operator*()
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (*getRightmost(category));
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

		GroupIterator& operator+=(int change)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (advanceIterator(+change, category));
		}

		GroupIterator& operator-=(int change)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			return (advanceIterator(-change, category));
		}

		reference operator[](int index)
		{
			typename std::iterator_traits<Iterator>::iterator_category category;
			GroupIterator copy(*this);

			copy.advanceIterator(index, category);
			return (*copy);
		}

		bool	operator==(const GroupIterator& other)
		{
			return (_group_iter == other._group_iter && _group_size == other._group_size);
		}

		bool	operator!=(const GroupIterator& other)
		{
			return (!operator==(other));
		}




	private:

		Iterator	_group_iter;
		size_t		_group_size;

		GroupIterator() {};



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

		Iterator getRightmost(std::random_access_iterator_tag)
		{
			Iterator iter = _group_iter;

			iter += _group_size - 1;
			return (iter);
		}

		Iterator getRightmost(std::bidirectional_iterator_tag)
		{
			Iterator iter = _group_iter;
			for (size_t i = 0; i < _group_size - 1; ++i)
				iter++;
			return (iter);
		}

		Iterator getRightmost(std::forward_iterator_tag)
		{
			Iterator iter = _group_iter;
			for (size_t i = 0; i < _group_size - 1; ++i)
				iter++;
			return (iter);
		}
};

template <
	typename Iterator
>
GroupIterator<Iterator> new_GroupIterator(Iterator it, std::size_t size)
{
	GroupIterator<Iterator> newIter(it, size);
	return (newIter);
}

template <
	typename Iterator
>
GroupIterator<Iterator> new_GroupIterator(GroupIterator<Iterator> it, std::size_t size)
{
	GroupIterator<Iterator> newIter(it.getIter(), size * it.getSize());
	return (newIter);
}

template<
	typename Iterator
>
void iter_swap(GroupIterator<Iterator> left, GroupIterator<Iterator> right)
{
	//std::cout << *left.getIter() << " " << *left.getLast() << " " << *right.getIter() << std::endl;
    std::swap_ranges(left.getIter(), left.getLast(), right.getIter());
}

template<typename Iterator>
GroupIterator<Iterator> operator+(GroupIterator<Iterator> it, std::size_t size)
{
    return it += size;
}

template<typename Iterator>
GroupIterator<Iterator> operator+(std::size_t size, GroupIterator<Iterator> it)
{
    return it += size;
}

template<typename Iterator>
GroupIterator<Iterator> operator-(GroupIterator<Iterator> it, std::size_t size)
{
    return it -= size;
}

template<typename Iterator>
typename GroupIterator<Iterator>::difference_type operator-(GroupIterator<Iterator>& left, GroupIterator<Iterator>& right)
{
    return (left.getIter() - right.getIter()) / left.getSize();
}

#endif
