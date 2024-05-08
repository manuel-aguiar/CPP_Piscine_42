/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 13:11:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "GroupIterator.hpp"
//#include "IterFuncs.hpp"
#include "FordJohnsonSort.hpp"
#include "QuickSort.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iomanip>


static void	print_num(int &num)
{
	std::cout << std::left << std::setw(2) << num << "  ";
}

template <
	typename GroupIterator
> void print_elements(GroupIterator begin, GroupIterator end)
{
	for	(GroupIterator iter(begin); begin != end; ++iter)
	{
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;
}

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

	std::for_each(list.begin(), list.end(), print_num);
	std::cout << std::endl;

	std::cout << "\nlist:" << std::endl;
	size_t count = QuickSort(list);

	std::cout << "Total Comparisons: " << count << std::endl;

	std::for_each(list.begin(), list.end(), print_num);
	std::cout << std::endl;

    return 0;
}

