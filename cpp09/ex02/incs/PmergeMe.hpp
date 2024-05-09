/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 09:41:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

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
    typename Allocator = std::allocator<T>
> class PmergeMe
{
	public:
		//Constructor/Destructor
		PmergeMe(int ac, char **av);
		~PmergeMe();

		//getters, not verbose, stays here
		Container<T, Allocator>&				getContainer(void) const 			{return (_numbers);}
		const std::string&						getName(void) const 				{return (_name_container);}
		double									getInsertTime(void) const			{return (_insert_time);}
		double									getSortTime(void) const				{return (_sort_time);}

		template <
			template <
				template <
					typename,
					typename
				> class,
				class,
				class
			> class SortingFunction
		>
		void									sort(SortingFunction<Container, T, Allocator> sort);
		bool									parse(void);

	private:
		int										_ac;
		char**									_av;
		static const std::string				g_type_info[4];
		static const std::string				g_type_name[4];

		Container<T, Allocator>					_numbers;
		const std::string						_name_container;

		double									_insert_time;
		double									_sort_time;

		size_t									_comp_count;

		const std::string&						deduceContainerName(void);
		bool									parse(int ac, char **av);
		void									dumpUnsorted(const std::vector<unsigned int>& unsorted);
		void									printNumbers(void) const;

		//Copy and assignment -> private
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

};

#include "../tpp/PmergeMe.tpp"

#endif
