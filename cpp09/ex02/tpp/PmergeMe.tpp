/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:33:42 by manuel            #+#    #+#             */
/*   Updated: 2024/05/09 13:21:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP

# define PMERGEME_TPP

#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#include <cerrno>
#include <sstream>

//sequence
#include <vector>
#include <deque>
#include <list>


//helper function
void	print_num(const unsigned int num);
bool is_only_spaces(const std::string& word);

//inform template about the holder class
template <
	typename T,
	template <
		typename,
		typename
	> class First,
	template <
		typename,
		typename
	> class Second,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
> class MergeInsertComp;


// Constructor
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
PmergeMe<T, Container, SortingFunction, Allocator>::PmergeMe(int ac, char **av) :
        _ac(ac),
        _av(av),
		_name_container(deduceContainerName()),
		_comp_count(0)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Default Constructor Called" << std::endl;
    #endif
};

// Destructor
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
PmergeMe<T, Container, SortingFunction, Allocator>::~PmergeMe()
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Destructor Called" << std::endl;
    #endif
};


//Copy Constructor and Assignment - private

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
PmergeMe<T, Container, SortingFunction, Allocator>::PmergeMe(const PmergeMe& copy)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Copy constructor Called" << std::endl;
    #endif
    (void)copy;
};


template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
PmergeMe<T, Container, SortingFunction, Allocator>&
PmergeMe<T, Container, SortingFunction, Allocator>::operator=(const PmergeMe& assign)
{
    #ifdef DEBUG_CONSTRUCTOR
        std::cout << "PmergeMe -" << _name_container << "- Assignment Called" << std::endl;
    #endif
    (void)assign;
    return (*this);
}

template<
	typename T
>
std::string	getAllContainerNames() {
	return typeid(T).name();
}

//statics to identify the underlying containers called
template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
const std::string		PmergeMe<T, Container, SortingFunction, Allocator>::g_type_info[4] =
{
	getAllContainerNames<std::vector		<T> >(),
	getAllContainerNames<std::list			<T> >(),
	getAllContainerNames<std::deque			<T> >(),
	"Unnallowed"
};

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
const std::string		PmergeMe<T, Container, SortingFunction, Allocator>::g_type_name[4] =
{
	"std::vector",
	"std::list",
	"std::deque",
	"Unnallowed"
};

//deduce container name

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
const std::string&	PmergeMe<T, Container, SortingFunction, Allocator>::deduceContainerName(void)
{
    int i = 0;
    std::string myType = typeid(_numbers).name();
    while (i < 3)
    {
        if (myType == g_type_info[i])
            return (g_type_name[i]);
        i++;
    }
    return (g_type_name[i]);
}

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
bool		PmergeMe<T, Container, SortingFunction, Allocator>::parse(void)
{
	std::string convert;
	std::string	itoa;
	long		number;

	if (!_av)
		return (false);

	for (int i = 0; i < _ac; ++i)
	{
		convert = _av[i];
		// check invalid characters or only spaces
		if (convert.find_first_not_of(VALID_CHARS, 0) != std::string::npos
		|| is_only_spaces(convert))
			return (false);
		std::stringstream ss(convert);
		while (true)
		{
			ss >> itoa;

			//nothing left to extract
			if (ss.fail()
			|| is_only_spaces(itoa))
				break ;

			//convertion and limit check
			number = std::strtol(itoa.c_str(), NULL, 10);
			if (errno == ERANGE
			|| number > std::numeric_limits<unsigned int>::max()
			|| number <= 0)
				return (false);

			//dump to unsorted vector
			_numbers.push_back(static_cast<unsigned int>(number));
		}
	}
	//std::cout << "Before: ";
	//std::for_each(_unsorted.begin(), _unsorted.end(), print_num);
	//std::cout << std::endl;
	return (true);
}

//Sort member function, that takes a functor

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
void		PmergeMe<T, Container, SortingFunction, Allocator>::sort()
{
    clock_t start;
    clock_t end;

    start = clock();
    if(!parse() || _numbers.size() == 0)
        throw std::runtime_error("Error");
    end = clock();
    _insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    start = end;
	_comp_count = _sorting_function(_numbers);
	end = clock();
	_sort_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}


template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
void		PmergeMe<T, Container, SortingFunction, Allocator>::printNumbers(void)
{
    std::cout << "Container - " << _name_container << " - numbers (" << _numbers.size() << " candidates)" << std::endl;
    std::for_each(_numbers.begin(), _numbers.end(), print_num);
    std::cout << "\n" << std::endl;
}

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
void		PmergeMe<T, Container, SortingFunction, Allocator>::printStats(void)
{
	std::cout 	<< "Container: " << _name_container
				<< " is sorted? "<< ((is_sorted(_numbers) && _numbers.size() == static_cast<size_t>(_ac)) ? "YES" : "NO")
				<< " (Total Comparisons: " << _comp_count << " for " << _numbers.size() << " candidates)" << std::endl;
    std::cout << "	Time to insert was: " << _insert_time << std::endl;
	std::cout << "	Time to sort was: " << _sort_time << std::endl;
	std::cout << "	Total processing time was: " << _insert_time + _sort_time << "\n" << std::endl;
}

template <
    typename T,
    template <
        typename,
        typename
    > class Container,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction,
	class Allocator
>
bool		PmergeMe<T, Container, SortingFunction, Allocator>::is_sorted(Container<T, Allocator>& container)
{
	typedef typename Container<T, Allocator>::iterator iter;

	iter rbegin = --(container.end());

	for(iter begin = container.begin(); begin != rbegin; ++begin)
	{
		if (*next(begin, 1) < *begin)
			return (false);
	}
	return (true);

};

#endif
