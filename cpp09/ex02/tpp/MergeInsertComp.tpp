/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:34:51 by manuel            #+#    #+#             */
/*   Updated: 2024/05/09 12:02:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MERGEINSERTCOMP_TPP

# define MERGEINSERTCOMP_TPP

# include "FordJohnsonSort.hpp"
# include "PmergeMe.hpp"

# include <algorithm>
# include <sstream>
# include <cerrno>
# include <limits>
# include <cstdio>

//helper functions
bool is_only_spaces(const std::string& word);

//constructor and driver
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
>  MergeInsertComp<T, First, Second, SortingFunction, Allocator>::MergeInsertComp(int ac, char **av) :
	_first(ac, av),
	_second(ac, av)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Parameter Constructor Called" << std::endl;
	#endif
	run(ac, av);
};


//Default Constructor - private
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
>  MergeInsertComp<T, First, Second, SortingFunction, Allocator>::MergeInsertComp()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Default Constructor Called" << std::endl;
	#endif
}


//Destructor

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
>  MergeInsertComp<T, First, Second, SortingFunction, Allocator>::~MergeInsertComp()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Destructor Called" << std::endl;
	#endif
};

//Copy constructor - private

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
>  MergeInsertComp<T, First, Second, SortingFunction, Allocator>::MergeInsertComp(const MergeInsertComp& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Copy Constructor Called" << std::endl;
	#endif
	(void)copy;
};

//Assignment operator - private

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
>  MergeInsertComp<T, First, Second, SortingFunction, Allocator>&
MergeInsertComp<T, First, Second, SortingFunction, Allocator>::operator=(const MergeInsertComp& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Assignment Called" << std::endl;
	#endif
	(void)assign; return (*this);
};


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
>
void	MergeInsertComp<T, First, Second, SortingFunction, Allocator>::run(int ac, char **av)
{
	(void)ac;
	(void)av;
	_first.sort();
	_second.sort();

	#ifdef _ALL_IN
		double							_insert_time;
		clock_t 						start;
		clock_t 						end;

		std::cout << std::endl;

		start = clock();
		if (!parse(ac, av))
			throw std::runtime_error("Error");
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to insert to a multiset:      " << _insert_time << std::endl;


		start = clock();
		if (!parse(ac, av, _vec))
			throw std::runtime_error("Error");
		std::sort(_vec.begin(), _vec.end());
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to std::sort a vector:        " << _insert_time << std::endl;

/*
		start = clock();
		if (!parse(ac, av, _deque))
			throw std::runtime_error("Error");
		std::sort(_deque.begin(), _deque.end());
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to std::sort a deque:         " << _insert_time << std::endl;
*/
		start = clock();
		if (!parse(ac, av, _list))
			throw std::runtime_error("Error");
		_list.sort();
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to list.sort():               " << _insert_time << std::endl;
	#endif
}


//number parsing


#ifdef _ALL_IN

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
	>
	template <
		class Inner
	>
	bool	MergeInsertComp<T, First, Second, SortingFunction, Allocator>::parse(int ac, char **av, Inner& container)
	{
		std::string convert;
		std::string	itoa;
		long		number;

		if (!av)
			return (false);

		for (int i = 0; i < ac; ++i)
		{
			convert = av[i];
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
				int res =  static_cast<unsigned int>(number);

				container.push_back(res);
			}
		}
		//std::cout << "Before: ";
		//std::for_each(_unsorted.begin(), _unsorted.end(), print_num);
		//std::cout << std::endl;
		return (true);
	}

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
	>
	bool	MergeInsertComp<T, First, Second, SortingFunction, Allocator>::parse(int ac, char **av)
	{
		std::string convert;
		std::string	itoa;
		long		number;

		if (!av)
			return (false);

		for (int i = 0; i < ac; ++i)
		{
			convert = av[i];
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
				int res =  static_cast<unsigned int>(number);

				_set.insert(res);
			}
		}
		//std::cout << "Before: ";
		//std::for_each(_unsorted.begin(), _unsorted.end(), print_num);
		//std::cout << std::endl;
		return (true);
	}

#endif


#endif
