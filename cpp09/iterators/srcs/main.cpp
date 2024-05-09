/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 08:28:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "GroupIterator.hpp"
//#include "IterFuncs.hpp"
#include "FordJohnsonSort.hpp"
#include "QuickSort.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iomanip>


//static void	print_num(int &num)
//{
//	std::cout << std::left << std::setw(2) << num << "  ";
//}

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

#include <ctime>

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
bool	is_sorted(Container<T, Alloc>& container)
{
	typedef typename Container<T, Alloc>::iterator iter;

	iter rbegin = --(container.end());

	for(iter begin = container.begin(); begin != rbegin; ++begin)
	{
		if (*next(begin, 1) < *begin)
			return (false);
	}
	return (true);

};

int main(void)
{
	srand(std::time(0));
	std::deque<int> deque;
    std::list<int> list;
    std::vector<int> vec;

	int total = 50001;
    for (int i = 1; i <= total; ++i)
	{
        //list.push_back((total - i + 1) * (i % 2 ? -1 : 1));
        //vec.push_back((total - i + 1) * (i % 2 ? -1 : 1));
		int num = (int)((rand() / (float)RAND_MAX) * 1000);
        list.push_back(num);
        vec.push_back(num);
		deque.push_back(num);
    }

	//std::for_each(list.begin(), list.end(), print_num);
	//std::cout << std::endl;

	//std::cout << "\nlist:" << std::endl;
	{
		size_t count = FordJohnsonSort(list);
		std::cout << "Total Comparisons: " << count << std::endl;
	}

	//std::for_each(list.begin(), list.end(), print_num);
	//std::cout << std::endl;

	{
		size_t count = FordJohnsonSort(vec);
		std::cout << "Total Comparisons: " << count << std::endl;
	}

	{
		size_t count = FordJohnsonSort(deque);
		std::cout << "Total Comparisons: " << count << std::endl;
	}

	if (is_sorted(list))
		std::cout << "OK list" << std::endl;
	else
		std::cout << "NOT OK list" << std::endl;

	if (is_sorted(vec))
		std::cout << "OK vector" << std::endl;
	else
		std::cout << "NOT OK vector" << std::endl;

	if (is_sorted(deque))
		std::cout << "OK deque" << std::endl;
	else
		std::cout << "NOT OK deque" << std::endl;
    return (0);
}

