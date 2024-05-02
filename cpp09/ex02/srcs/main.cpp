/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/02 10:42:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <string>

int main(void)
{
	PmergeMe<std::list<int> > list;
	PmergeMe<std::multiset<int> > set;

	list.insertContainer(3);
	set.insertContainer(3);
	std::cout << list.getName() << std::endl;
	std::cout << set.getName() << std::endl;

    return (0);
}
