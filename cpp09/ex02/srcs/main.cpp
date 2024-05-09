/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 10:17:43 by codespace        ###   ########.fr       */
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

int main1(void)
{
	srand(std::time(0));
	std::deque<int> deque;
    std::list<int> list;
    std::vector<int> vec;

	int total = 11;
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


#include "MergeInsertComp.hpp"

#include <string>

	/*
		This.. is... the painkiiii......   super convoluted code.
		I'm sorry to my evaluators.
		Most of this is totally useless, all this template stuff
		Don't do it.
		I'm doing it because we are in school and this is the time to explore.
		But don't, please.
	*/

int main(int ac, char **av)
{
	try
	{
		MergeInsertComp<unsigned int, std::vector, std::deque> comp(--ac, ++av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}

	/*
		./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`
	*/


