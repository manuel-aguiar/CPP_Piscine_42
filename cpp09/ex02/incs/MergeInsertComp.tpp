/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:34:51 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 10:00:47 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MERGEINSERTCOMP_TPP

# define MERGEINSERTCOMP_TPP

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
	_count(ac),
	_first(g_type_info, g_type_name),
	_second(g_type_info, g_type_name)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MergeInsertComp Parameter Constructor Called" << std::endl;
	#endif
	if (!parse(ac, av))
	{
		CERR("Error");
		return ;
	}
	_first.sort(_unsorted);
	_second.sort(_unsorted);
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


//statics to identify the underlying containers called
template<
	typename T
>
std::string	getAllContainerNames() {
	return typeid(T).name();
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
	> class Second
> const std::string	MergeInsertComp<T, First, Second>::g_type_info[4] =
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
	> class First,
	template <
		typename,
		typename
	> class Second
> const std::string	MergeInsertComp<T, First, Second>::g_type_name[4] =
{
	"std::vector",
	"std::list",
	"std::deque",
	"Unnallowed"
};


//number parsing
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
> bool	MergeInsertComp<T, First, Second>::parse(int ac, char **av)
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
			_unsorted.push_back(static_cast<unsigned int>(number));
		}
	}
	std::cout << "Before: ";
	std::for_each(_unsorted.begin(), _unsorted.end(), print_num);
	std::cout << std::endl;
	return (true);
}

#endif