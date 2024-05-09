/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 12:49:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

#include "FordJohnsonSort.hpp"

#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <set>
#include <ctime>

#include <string>

//sequence
#include <vector>
#include <deque>
#include <list>

# define CERR(x) std::cerr << (x) << std::endl
# define VALID_CHARS "0123456789 \n\t\v\b"

template <
    typename T = unsigned int,
    template <
        typename,
        typename
    > class Container = std::vector,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction = FordJohnsonFunctor,
	typename Allocator = std::allocator<T>
> class PmergeMe
{
	public:
		//Constructor/Destructor
		PmergeMe(int ac, char **av);
		~PmergeMe();

		//getters, not verbose, stays here
		Container<T, Allocator>&					getContainer(void) const 			{return (_numbers);}
		const std::string&							getName(void) const 				{return (_name_container);}
		double										getInsertTime(void) const			{return (_insert_time);}
		double										getSortTime(void) const				{return (_sort_time);}

		void										sort();

		void										printStats(void);
		void										printNumbers(void);

	private:
		int											_ac;
		char**										_av;
		static const std::string					g_type_info[4];
		static const std::string					g_type_name[4];

		Container<T, Allocator>						_numbers;
		SortingFunction<Container, T, Allocator>	_sorting_function;
		const std::string							_name_container;

		double										_insert_time;
		double										_sort_time;

		size_t										_comp_count;

		bool										parse(void);
		bool										is_sorted(Container<T, Allocator>& container);
		const std::string&							deduceContainerName(void);


		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

};

#include "../tpp/PmergeMe.tpp"

#endif
