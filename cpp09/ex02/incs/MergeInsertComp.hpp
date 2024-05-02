/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:00:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 12:33:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTCOMP_HPP

# define MERGEINSERTCOMP_HPP

#include "PmergeMe.hpp"

# include <algorithm>
# include <sstream>
# include <cerrno>
# include <limits>
# include <cstdio>

# define CERR(x) std::cerr << (x) << std::endl
# define VALID_CHARS "0123456789 \n\t\v\b"


template <
	class First,
	class Second
> class MergeInsertComp
{
	public:
		MergeInsertComp(int ac, char **av) : _count(ac)
		{
			#ifdef DEBUG_CONSTRUCTOR
				std::cout << "MergeInsertComp Constructor Called" << std::endL;
			#endif
			std::cout << "first container is: " << _first.getName() << std::endl;
			std::cout << "second container is: " << _second.getName() << std::endl;
			if (!parse(ac, av))
			{
				CERR("Error");
				return ;
			}

			std::cout << "hello world!" << std::endl;
		};
		~MergeInsertComp() {};

		bool	parse(int ac, char **av);

		size_t								getCount(void) const {return (_count);}
		const std::vector<unsigned int>&	getUnsorted(void) const {return (_unsorted);}
		PmergeMe<First>&					getFirst(void) const {return (_first);}
		PmergeMe<Second>&					getSecond(void) const {return (_second);}

	private:
		std::vector<unsigned int>	_unsorted;
		size_t						_count;



		PmergeMe<First>		_first;
		PmergeMe<Second>	_second;

		MergeInsertComp(const MergeInsertComp& copy) {(void)copy;};
		MergeInsertComp& operator=(const MergeInsertComp& assign) {(void)assign; return (*this);};
};


int	is_only_spaces(std::string& word)
{
	for (std::string::iterator iter = word.begin(); iter != word.end(); ++iter)
	{
		if (*iter != '\n'
		&& *iter != '\t'
		&& *iter != '\v'
		&& *iter != ' '
		&& *iter != '\b')
			return (false);
	}
	return (true);
}

void	print_num(const int num)
{
	std::cout << num << " ";
}

template <
	class First,
	class Second
>
bool	MergeInsertComp<First, Second>::parse(int ac, char **av)
{
	std::string convert;
	std::string	itoa;
	long		number;

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
