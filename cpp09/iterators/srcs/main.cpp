/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 11:37:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnsonSort.tpp"
#include "GroupIterator.tpp"
#include "IterFuncs.tpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iomanip>



int main(void)
{
    std::list<int> list;
    std::vector<int> vec;

	int total = 13;
    for (int i = 1; i <= total; ++i)
	{
        list.push_back((total - i + 1) * (i % 2 ? -1 : 1));
        vec.push_back((total - i + 1) * (i % 2 ? -1 : 1));
    }

	std::for_each(list.begin(), list.end(), print_number);
	std::cout << std::endl;

	std::cout << "\nlist:" << std::endl;
	size_t count = FordJohnsonSort(list);

	std::cout << "Total Comparisons: " << count << std::endl;

	std::for_each(list.begin(), list.end(), print_number);
	std::cout << std::endl;

    return 0;
}

