/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 12:13:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnsonSort.hpp"
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
	size_t count = FordJohnsonSort(list);

	std::cout << "Total Comparisons: " << count << std::endl;

	std::for_each(list.begin(), list.end(), print_num);
	std::cout << std::endl;

    return 0;
}

