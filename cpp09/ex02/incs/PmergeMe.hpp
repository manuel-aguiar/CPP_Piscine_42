/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/03 10:07:59 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <set>

#include <string>

//sequence
#include <vector>
#include <deque>
#include <list>




// ILLEGAL FUNCTION HERE, MOVE TO .CPP FILE
static void	print_num(const unsigned int num)
{
	std::cout << num << " ";
}

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
		PmergeMe(	const std::string (&g_type_info)[4],
					const std::string (&g_type_name)[4]);
		~PmergeMe();

		//getters, not verbose, stays here
		Container<T, Allocator>&				getContainer(void) const 			{return (_numbers);}
		Container<std::pair<T,T>, Allocator>&	getPairs(void) const 				{return (_pairs);}
		const std::string&						getName(void) const 				{return (_name_container);}

		void									sort(const std::vector<unsigned int>& unsorted)
		{
			dumpUnsorted(unsorted);
			printNumbers();
		}

		void									dumpUnsorted(const std::vector<unsigned int>& unsorted)
		{
			_numbers.insert(_numbers.end(), unsorted.begin(), unsorted.end());
		}

		void									printNumbers(void) const
		{
			std::cout << "Container - " << _name_container << " - numbers: ";
			std::for_each(_numbers.begin(), _numbers.end(), print_num);
			std::cout << std::endl;
		}

	private:

		const std::string						(&_g_type_info)[4];
		const std::string						(&_g_type_name)[4];

		Container<T, Allocator>					_numbers;
		Container<std::pair<T,T>, Allocator>	_pairs;
		const std::string						_name_container;

		const std::string&						deduceContainerName(void);


		//Copy and assignment -> private
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

};

#include "PmergeMe.tpp"

#endif
