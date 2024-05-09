/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:34:51 by manuel            #+#    #+#             */
/*   Updated: 2024/05/09 09:48:19 by codespace        ###   ########.fr       */
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
int	is_only_spaces(std::string& word);

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
	> class Second
> MergeInsertComp<T, First, Second>::MergeInsertComp(int ac, char **av) :
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
	> class Second
> MergeInsertComp<T, First, Second>::MergeInsertComp()
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
	> class Second
> MergeInsertComp<T, First, Second>::~MergeInsertComp()
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
	> class Second
> MergeInsertComp<T, First, Second>::MergeInsertComp(const MergeInsertComp& copy)
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
	> class Second
> MergeInsertComp<T, First, Second>& MergeInsertComp<T, First, Second>::operator=(const MergeInsertComp& assign)
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
	> class Second
> void MergeInsertComp<T, First, Second>::run(int ac, char **av)
{
	(void)ac;
	(void)av;
	_first.sort(FordJohnson<First, T, std::allocator<T> >());
	_second.sort(FordJohnson<Second, T, std::allocator<T> >());

	#ifdef _ALL_IN
		std::multiset<T>				_set;
		std::vector<T>					_vec;
		double							_insert_time;
		clock_t 						start;
		clock_t 						end;

		start = clock();
		if (!parse(ac, av, _set))
			throw std::runtime_error("Error");
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to insert to a multiset: " << _insert_time << std::endl;

		start = clock();
		if (!parse(ac, av, _vec))
		{
			CERR("Error");
			return ;
		}
		std::sort(_vec.begin(), _vec.end());
		end = clock();
		_insert_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to insert and std::sort a vector: " << _insert_time << std::endl;
	#endif
}


//number parsing


/*
template <
	typename T,
	template <
		typename,
		typename
	> class First,
	template <
		typename,
		typename
	> class Second
>
template<
	class Inner
>
bool	MergeInsertComp<T, First, Second>::parse(int ac, char **av, Inner& container)
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
			container.insert(container.end(), static_cast<unsigned int>(number));
		}
	}
	//std::cout << "Before: ";
	//std::for_each(_unsorted.begin(), _unsorted.end(), print_num);
	//std::cout << std::endl;
	return (true);
}

*/

#endif