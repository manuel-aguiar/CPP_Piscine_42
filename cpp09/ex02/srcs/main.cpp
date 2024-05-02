/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/02 12:27:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

#include <string>


int main(int ac, char **av)
{
	MergeInsertComp<std::list<unsigned int>,  std::vector<unsigned int> > comp(--ac, ++av);

    return (0);
}

int main1(void)
{
	PmergeMe<std::list<int> > list;
	PmergeMe<std::multiset<int> > set;

	list.insertContainer(3);
	set.insertContainer(3);
	std::cout << list.getName() << std::endl;
	std::cout << set.getName() << std::endl;

    return (0);
}
