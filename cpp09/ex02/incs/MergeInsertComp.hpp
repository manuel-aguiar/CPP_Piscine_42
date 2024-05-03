/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:00:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/03 09:47:16 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTCOMP_HPP

# define MERGEINSERTCOMP_HPP

# include "PmergeMe.hpp"

# include <algorithm>
# include <sstream>
# include <cerrno>
# include <limits>
# include <cstdio>

# define CERR(x) std::cerr << (x) << std::endl
# define VALID_CHARS "0123456789 \n\t\v\b"

template <
	typename T = unsigned int,
	template <
		typename,
		typename
	> class First = std::vector,
	template <
		typename,
		typename
	> class Second = std::deque
> class MergeInsertComp
{
	public:
		MergeInsertComp(int ac, char **av);
		~MergeInsertComp();

		
		//getters
		size_t								getCount(void) const 		{return (_count);}
		const std::vector<unsigned int>&	getUnsorted(void) const 	{return (_unsorted);}
		PmergeMe<T, First>&					getFirst(void) const 		{return (_first);}
		PmergeMe<T, Second>&				getSecond(void) const 		{return (_second);}

	private:

		static const std::string		g_type_info[4];
		static const std::string		g_type_name[4];
		std::vector<unsigned int>		_unsorted;
		size_t							_count;

		PmergeMe<T, First>				_first;
		PmergeMe<T, Second>				_second;

		bool							parse(int ac, char **av);

		//Private copy and assignment
		MergeInsertComp(const MergeInsertComp& copy);
		MergeInsertComp& operator=(const MergeInsertComp& assign);
};

// ILLEGAL FUNCTION HERE, MOVE TO .CPP FILE

int	is_only_spaces(std::string& word);

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

#include "MergeInsertComp.tpp"

#endif

/*

	template madness........

		#include <iostream>
		#include <vector>
		#include <list>
		#include <deque>
		#include <set>


		template <
			typename T = int,
			template <
				typename,
				typename
			> class Container = std::vector,
			typename Allocator = std::allocator<T>
		>
		class ContainerWrapper {
		public:
			// Constructor
			ContainerWrapper() {}

			// Member function to add elements
			void addElement(const T& element) {
				container.push_back(element); // Example operation on the container
			}

			void addPair(const T& first, const T& second)
			{
				pairs.push_back(std::make_pair(first, second));
			}


		private:
			Container<T, Allocator >                   container; // Container with provided traits
			Container<std::pair<T,T>, Allocator >     pairs;
		};


		template <
			typename T = int,
			template <
				typename,
				typename
			> class First = std::vector,
			template <
				typename,
				typename
			> class Second = std::deque
		>
		class Holder
		{
		private:
			ContainerWrapper<T, First> first;
			ContainerWrapper<T, Second> second;
		};


		int main()
		{
			Holder<int, std::vector, std::list> wtf;
			Holder<int, std::deque, std::list> cenas;

			Holder<std::vector<int>, std::vector, std::vector> crazy;

			Holder<> empty;

			(void)wtf;
			(void)cenas;
			(void)crazy;
			(void)empty;
			return 0;
		}


*/
