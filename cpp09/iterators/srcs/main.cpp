/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 15:50:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterators.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

int g_comp_count = 0;

template <
	typename GroupIterator
> void print_elements(GroupIterator begin, GroupIterator end)
{
	for	(GroupIterator iter(begin); begin != end; ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

template <
	typename GroupIterator
>
void	recursive(GroupIterator begin, GroupIterator end)
{
	size_t size = std::distance(begin, end);
	if (size < 2)
		return ;

	bool	has_straggler = size % 2;
	GroupIterator newEnd = (has_straggler) ? --end : end;
	//print_elements(begin, newEnd);
	for (GroupIterator iter(begin); iter != newEnd; iter += 2)
	{
		g_comp_count++;
		if (iter[0] > iter[1])
			iter_swap(iter, iter + 1);
	}
	recursive(
		new_GroupIterator(begin, 2),
		new_GroupIterator(newEnd, 2)
	);

}

template <
	typename Iterator
>
void	mysort(Iterator begin, Iterator end)
{
	g_comp_count = 0;

	recursive(
		new_GroupIterator(begin, 1),
		new_GroupIterator(end, 1)
	);
	for(Iterator iter = begin; iter != end; ++iter)
		std::cout << *iter << "  ";
	std::cout << std::endl;
	std::cout << "Total Comparisons: " << g_comp_count << std::endl;
}

int main(void)
{
    std::list<int> list;
    std::vector<int> vec;

	int total = 22;
    for (int i = 1; i <= total; ++i)
	{
        list.push_back(total - i);
        vec.push_back(total - i);
    }

	//GroupIterator<std::vector<int>::iterator> gvec(vec.begin(), 3);
    //std::cout << "Vector iterator: " << gvec[0] << std::endl; // Should print 2
//
	//GroupIterator<std::list<int>::iterator> glist(list.begin(), 2);
	//GroupIterator<std::list<int>::iterator> gliste(list.end(), 2);
    ////std::cout << "List iterator: " << std::binary_search(glist, gliste, 1) << std::endl; // Should print 2

	mysort<std::list<int>::iterator >(list.begin(), list.end());
	//mysort<std::vector<int>::iterator >(vec.begin(), vec.end());

    return 0;
}

