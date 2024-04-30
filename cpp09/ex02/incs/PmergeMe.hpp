/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:14:45 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 15:40:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

#include <set>
#include <list>

template <
	class Container
>
class PmergeMe
{
	public:
		PmergeMe() {};
		~PmergeMe() {};

		void	insertContainer(int n)
		{
			_numbers.push_back(n);
		}

	private:
		Container		_numbers;

		PmergeMe(const PmergeMe& copy) {(void)copy;};
		PmergeMe& operator=(const PmergeMe& assign) {(void)assign; return (*this);};
};



#endif
