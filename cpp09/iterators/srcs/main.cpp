/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 11:39:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterators.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iomanip>

int g_comp_count = 0;

const size_t jacobsthal_diff[] = {
2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};


void	print_number(int &num)
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

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc,
	typename GroupIterator
>
void	recursive(Container<T, Alloc>& container, GroupIterator begin, GroupIterator end)
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
		//std::cout << "before swap: " << iter[0] << " " << (iter + 1)[0] << std::endl;
		if (iter[0] > iter[1])
			iter_swap(iter, iter + 1);
		//else
		//	std::cout << "didn't swap" << std::endl;
		//std::cout << "after swap: " << iter[0] << " " << iter[1] << std::endl;
	}
	std::for_each(container.begin(), container.end(), print_number);
	std::cout << std::endl;

	recursive(
		container,
		new_GroupIterator(begin, 2),
		new_GroupIterator(newEnd, 2)
	);

	//typedef for main chain and its iterator
	typedef Container<GroupIterator, Alloc>                     mainChainContainer;
	typedef typename mainChainContainer::iterator				mainChainIterator;

	//typedef for pending chain and its iterator
	typedef Container<mainChainIterator, Alloc>					pendingChainContainer;
	typedef typename pendingChainContainer::iterator 			pendingChainIterator;


	mainChainContainer											main;
	pendingChainContainer										pending;

	main.push_back(begin);
	main.push_back(begin.next(1));

	for (GroupIterator iter(begin + 2); iter != newEnd; iter += 2)
	{
		typename Container<GroupIterator, Alloc>::iterator tmp = main.insert(main.end(), iter.next(1));
		pending.push_back(tmp);
	}

	if (has_straggler)
		pending.push_back(main.end());

	GroupIterator 						main_it(begin + 2);
	pendingChainIterator 				pend_it(pending.begin());

	(void)main_it;
	(void)pend_it;
}

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
void	mysort(Container<T, Alloc>& container)
{
	g_comp_count = 0;

	typename Container<T, Alloc>::iterator begin = container.begin();
	typename Container<T, Alloc>::iterator end = container.end();

	recursive(
		container,
		new_GroupIterator(begin, 1),
		new_GroupIterator(end, 1)
	);
	std::cout << "Total Comparisons: " << g_comp_count << std::endl;
}

int main(void)
{
    std::list<int> list;
    std::vector<int> vec;

	int total = 15;
    for (int i = 1; i <= total; ++i)
	{
        list.push_back(total - i + 1);
        vec.push_back(total - i + 1);
    }

	std::for_each(list.begin(), list.end(), print_number);
	std::cout << std::endl;

	//GroupIterator<std::vector<int>::iterator> gvec(vec.begin(), 3);
    //std::cout << "Vector iterator: " << gvec[0] << std::endl; // Should print 2
//
	//GroupIterator<std::list<int>::iterator> glist(list.begin(), 2);
	//GroupIterator<std::list<int>::iterator> gliste(list.end(), 2);
    ////std::cout << "List iterator: " << std::binary_search(glist, gliste, 1) << std::endl; // Should print 2


	std::cout << "\nlist:" << std::endl;
	mysort(list);

	std::for_each(list.begin(), list.end(), print_number);
	std::cout << std::endl;

/*
	std::cout << "\nvector:" << std::endl;
	mysort(vec);

	for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << *iter << "  ";
	std::cout << std::endl;
	//mysort<std::vector<int>::iterator >(vec.begin(), vec.end());
*/
    return 0;
}

