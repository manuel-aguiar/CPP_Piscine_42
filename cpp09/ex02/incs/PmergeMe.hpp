/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 10:46:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

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

template <
	class Container
>
class PmergeMe
{
	public:
		PmergeMe() : _name_container(searchContainerName()) {std::cout << "address of static is: " << &some_variable << std::endl;};
		~PmergeMe() {};

		void	insertContainer(int n)
		{
			_numbers.insert(_numbers.end(), n);
		}

		void	deduce_type(void);

		Container&				getContainer(void) const
		{
			return (_numbers);
		}

		const std::string&		getName(void) const
		{
			return (_name_container);
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

		static int some_variable;

		PmergeMe(const PmergeMe& copy) {(void)copy;};
		PmergeMe& operator=(const PmergeMe& assign) {(void)assign; return (*this);};

};



#endif
