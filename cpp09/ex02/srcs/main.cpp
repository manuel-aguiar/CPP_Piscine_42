/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/02 15:45:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

#include <string>


int main(int ac, char **av)
{
	MergeInsertComp<unsigned int, std::list,  std::vector> comp(--ac, ++av);

    return (0);
}

int main1(void)
{
	PmergeMe<std::list<int> > list;
	PmergeMe<std::multiset<int> > set;

	std::cout << list.getName() << std::endl;
	std::cout << set.getName() << std::endl;

    return (0);
}
