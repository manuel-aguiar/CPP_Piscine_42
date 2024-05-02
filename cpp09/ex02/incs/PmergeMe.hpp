/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 12:56:39 by codespace        ###   ########.fr       */
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
	class Container
>
class PmergeMe
{
	public:
		PmergeMe() : _name_container(searchContainerName()) {};
		~PmergeMe() {};

		void	insertContainer(int n)
		{
			_numbers.insert(_numbers.end(), n);
		}

		Container&				getContainer(void) const
		{
			return (_numbers);
		}


		const std::string&		getName(void) const
		{
			return (_name_container);
		}

		void					sort(const std::vector<unsigned int>& unsorted)
		{
			dumpUnsorted(unsorted, _numbers);
			printNumbers();
		}

		template <
			template <
				typename,
				typename
			> class Sequencial,
			class T,
			class Alloc
		>
		void					dumpUnsorted(const std::vector<unsigned int>& unsorted, Sequencial<T, Alloc>& mine)
		{
			mine.insert(_numbers.end(), unsorted.begin(), unsorted.end());
		}

		template <
			template <
				typename,
				typename,
				typename
			> class Associative,
			class T,
			class Alloc,
			class Compare
		>
		void					dumpUnsorted(const std::vector<unsigned int>& unsorted, Associative<T, Alloc, Compare>& mine)
		{
			mine.insert(unsorted.begin(), unsorted.end());
		}

		void					printNumbers(void) const
		{
			std::cout << "Container - " << _name_container << " - numbers: ";
			std::for_each(_numbers.begin(), _numbers.end(), print_num);
			std::cout << std::endl;
		}

	private:
		Container				_numbers;
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
