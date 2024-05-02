/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 15:44:41 by codespace        ###   ########.fr       */
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

//associative
//	using only std::multiset which allows doubled keys
//	std::map/multimap doesn't make sense in this case
#include <set>


extern const std::string	g_type_info[5];
extern const std::string	g_type_name[5];

static void	print_num(const unsigned int num)
{
	std::cout << num << " ";
}

template <
    typename T = int,
    template <
        typename,
        typename
    > class Container = std::vector,
    typename Allocator = std::allocator<T>
> class PmergeMe
{
	public:
		PmergeMe() : _name_container(searchContainerName()) {};
		~PmergeMe() {};

		Container<T, Allocator>&				getContainer(void) const {return (_numbers);}
		Container<std::pair<T,T>, Allocator>&	getPairs(void) const {return (_pairs);}
		const std::string&						getName(void) const {return (_name_container);}

		void						sort(const std::vector<unsigned int>& unsorted)
		{
			dumpUnsorted(unsorted);
			printNumbers();
		}

		void					dumpUnsorted(const std::vector<unsigned int>& unsorted)
		{
			_numbers.insert(_numbers.end(), unsorted.begin(), unsorted.end());
		}

		void					printNumbers(void) const
		{
			std::cout << "Container - " << _name_container << " - numbers: ";
			std::for_each(_numbers.begin(), _numbers.end(), print_num);
			std::cout << std::endl;
		}

	private:
		Container<T, Allocator>					_numbers;
		Container<std::pair<T,T>, Allocator >	_pairs;
		const std::string		_name_container;

		const std::string&		searchContainerName(void)
		{
			int i = 0;
			std::string myType = typeid(_numbers).name();
			while (i < 4)
			{
				if (myType == g_type_info[i])
					return (g_type_name[i]);
				i++;
			}
			return (g_type_name[i]);
		}

		PmergeMe(const PmergeMe& copy) {(void)copy;};
		PmergeMe& operator=(const PmergeMe& assign) {(void)assign; return (*this);};

};



#endif
