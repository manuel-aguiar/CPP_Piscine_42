/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnsonSort.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:25:10 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 09:18:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORDJOHNSON_TPP

# define FORDJOHNSON_TPP

# include "GroupIterator.hpp"
# include "IterFuncs.hpp"

# include <algorithm>
# include <iomanip>
# include <list>

/* FordJohnson sort (merge-insertion), returns the total number of comparisons */
template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	FordJohnsonSort(Container<T, Alloc>& container);

template <
	class T
>
static void	print_number(T& num)
{
	std::cout << std::left << std::setw(2) << num << "  ";
}

template <
	template <
		typename,
		typename
	> class Container,
	typename GroupIterator,
	class Alloc
> typename Container<GroupIterator, Alloc>::iterator
binary_search_count(typename Container<GroupIterator, Alloc>::iterator begin,
					typename Container<GroupIterator, Alloc>::iterator end,
					GroupIterator value, size_t& g_comp_count)
{
	typedef typename Container<GroupIterator, Alloc>::iterator iterator;

	while (static_cast<size_t>(std::distance(begin, end)) != 1)
	{
		iterator mid = next(begin, static_cast<size_t>(std::distance(begin, end) / 2));
		g_comp_count++;
		if (*value > **mid)
			begin = mid;
		else
			end = mid;
	}
	return (begin);
}

/*
	template <
		class Iterator
	> int my_iter_distance(Iterator begin, Iterator end)
	{

	}
*/

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc,
	typename GroupIterator
>
static void	_recursive(Container<T, Alloc>& container, GroupIterator begin, GroupIterator end, size_t& g_comp_count)
{

	/*
	0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691

	below is jacobsthal + 1
	*/
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

	size_t size = std::distance(begin, end);
	if (size < 2)
		return ;

	bool	has_straggler = size % 2;
	GroupIterator newEnd = (has_straggler) ? prev(end, 1) : end;
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


	_recursive(
		container,
		new_GroupIterator(begin, 2),
		new_GroupIterator(newEnd, 2),
		g_comp_count
	);

	//std::for_each(container.begin(), container.end(), print_number<T>);
	//std::cout << std::endl;

	//typedef for main chain and its iterator


	//typedef std::list<GroupIterator, Alloc>                     		mainChainContainer;

	typedef Container<GroupIterator, Alloc>                     		mainChainContainer;

		//have to use a list here..... OG author also did, because insertion will
		//invalidate the saved iterators if they belong to a vector
		//elements move physically in memory + risk of realloc

	typedef typename mainChainContainer::iterator						mainChainIterator;

	typedef Container<int, Alloc>										pendChainContainer;
	typedef typename pendChainContainer::iterator						pendChainIterator;


	//separating main and pending
	mainChainContainer													main;
	pendChainContainer													pending;

	main.push_back(begin);
	main.push_back(begin.next(1));

	//std::cout << "shadow pending:" << std::endl;
	for (GroupIterator iter(begin + 2); iter != newEnd; iter += 2)
	{
		mainChainIterator temp = main.insert(main.end(), iter.next(1));
		pending.push_back(static_cast<int>(std::distance(main.begin(), temp)));
		//std::cout << *iter << std::endl;
	}
	//std::cout << std::endl;
	if (has_straggler)
	{
		pending.push_back(static_cast<int>(std::distance(main.begin(),main.end())));
		//std::cout << "has straggler" << std::endl;
		/*
			if it has a straggler, binary search for the last element must be done
			against the full main chain (until the "end");
		*/
	}
	//else
	//	std::cout << "no straggler" << std::endl;


	//std::cout << "Printing FullChain (size " << static_cast<size_t>(std::distance(begin, newEnd)) << "): " << std::endl;
	//for (GroupIterator iter(begin); iter != newEnd; ++iter)
	//	std::cout << std::left << std::setw(2) << *iter << "  ";
	//std::cout << std::endl;


	//std::cout << "Printing mainChain (size " << main.size() << "): " << std::endl;
	//for (mainChainIterator iter = main.begin(); iter != main.end(); ++iter)
	//	std::cout << std::left << std::setw(2) << **iter << "  ";
	//std::cout << std::endl;


	//pend chain doesn't store any values, just keeps track of the position to perform binary search


	//std::cout << "Printing pendingChain (size " << pending.size() << "): " << std::endl;
	//for (pendChainIterator iter = pending.begin(); iter != pending.end(); ++iter)
	//	std::cout << std::left << std::setw(2) << **iter << "  ";
	//std::cout << std::endl;

	GroupIterator 						current_orig = begin + 2;
	pendChainIterator  					current_pend = pending.begin();

	int insertion_counter = 0;

	int i = 0;
	while (true)
	{
		int distance = jacobsthal_diff[i];

		if (distance >= static_cast<int>(std::distance(current_pend, pending.end())))
			break ;
		//std::cout << "distance is " << distance << " vs pending list: " << static_cast<int>(std::abs(std::distance(current_pend, pending.end()))) << std::endl;

		GroupIterator 				move_orig 		= next(current_orig, distance * 2);
		pendChainIterator 			move_pend 		= next(current_pend, distance);

		do
		{
			//std::cout <<  "starting do loop: " << (*move_pend == main.end()) << std::endl;

			move_orig -= 2;
			--move_pend;


			//std::cout << "preping binary search" << std::endl;
			//std::cout 	<< "binary search distance: " << static_cast<int>(std::abs(std::distance(main.begin(), *move_pend))) << std::endl;
			//std::cout 	<< "binary search distance: " << static_cast<int>(std::abs(std::distance(main.begin(), *move_pend)))
			//			<< " from: " << **main.begin() << " to: " << (*move_pend == main.end() ? 123123123123123UL : ***move_pend)
			//			<<", target is : " << *move_orig << std::endl;

			//<Container<GroupIterator, Alloc>, Alloc, GroupIterator >
			//mainChainIterator position = binary_search_count<mainChainContainer, GroupIterator, Alloc>(main.begin(), *move_pend, move_orig);

			mainChainIterator copy_begin = main.begin();
			//mainChainIterator copy_end = merged.end();
			//std::cout << "MOVE PEND: " << *move_pend << std::endl;
			mainChainIterator copy_end = next(copy_begin, *move_pend + insertion_counter);

			//std::cout << "derefing empty iterator?" << std::endl;

			int dist = static_cast<int>(std::distance(copy_begin, copy_end));
			//std::cout << "distance from copy begin to copy end: " << dist << " copy_begin : "
			//			<<  **copy_begin << "copy_end : " <<  **copy_end<< " target: " << *move_orig << std::endl;
			//std::cout << "calculating distance " << std::endl;
			while (dist)
			{

				//std::cout <<"advancing " << std::endl;
				mainChainIterator mid = next(copy_begin, dist / 2);
				g_comp_count++;

				//std::cout 	<< "begin: " << **copy_begin << ", end: " << (copy_end == main.end() ? 123123123123123UL : **copy_end)

				//		<< ", original: " << *move_orig << ", mid: " << **mid << std::endl;

				//std::cout << "attempt dereferencing" << std::endl;
				if (*move_orig > **mid)
				{

					//std::cout << "prevmid value: " << **mid;
					copy_begin = next(mid, 1);

					//std::cout << "	begin = mid, new begin: " << **copy_begin << " mid is now: " << **mid << std::endl;
				}
				else
				{
					copy_end = mid;

					//std::cout << "	end = mid, new end: " << **copy_end << std::endl;
				}
				dist = static_cast<int>(std::abs(std::distance(copy_begin, copy_end)));

				//std::cout << dist << std::endl;

				//std::cout << "print distance" << std::endl;
			}


			//std::cout << "hello? inserting" << *move_orig << " at " << **copy_end << std::endl;

			main.insert(copy_end, move_orig);

			insertion_counter++;

			//std::cout << "Printing Merged (size " << main.size() << "): " << std::endl;
			//for (mainChainIterator iter = main.begin(); iter != main.end(); ++iter)
			//	std::cout << std::left << std::setw(2) << **iter << "  ";
			//std::cout << std::endl;

			//std::cout << "inserted?" << std::endl;

			//binary search let's go

			//insert: mainChainIterator
			//start: mainChainIterator = main.begin();
			//end: mainChainIterator = *pend_last
			//mid:
		} while (move_pend != current_pend);


		//std::cout << "exited?" << std::endl;

		current_orig = next(current_orig, distance * 2);
		current_pend = next(current_pend, distance);

		//std::cout << "hey " << std::endl;
		i++;
	}

	//std::cout << "check pending" << std::endl;
	while (current_pend != pending.end())
	{

		//std::cout << "pending has elements" << std::endl;
		mainChainIterator copy_begin = main.begin();
		mainChainIterator copy_end = next(copy_begin, *current_pend + insertion_counter);
		//mainChainIterator copy_end = next(merged.begin(), *current_pend + insertion_counter);


		//std::cout << "derefing empty iterator?" << std::endl;

		int dist = static_cast<int>(std::distance(copy_begin, copy_end));

		//std::cout << "calculating distance " << std::endl;
		while (copy_begin != copy_end)
		{

			//std::cout <<"advancing, distance:  " << dist << std::endl;
			mainChainIterator mid = next(copy_begin, dist / 2);
			g_comp_count++;
			//std::cout << "attempt dereferencing " << **copy_begin  << std::endl;
			//std::cout 	<< "begin: " << **copy_begin << ", end: " << (copy_end == main.end() ? 123123123123123UL : **copy_end)
			//			<< ", original: " << *current_orig << ", mid: " << **mid << std::endl;

			//std::cout << "dereference successfull" << std::endl;
			if (*current_orig > **mid)
			{

				//std::cout << "prevmid value: " << **mid;
				copy_begin = next(mid, 1);

				//std::cout << "	begin = mid, new begin: " << **copy_begin << " mid is now: " << **mid << std::endl;
			}
			else
			{
				copy_end = mid;

				//std::cout << "	end = mid, new end: " << **copy_end << std::endl;
			}

			dist = static_cast<int>(std::distance(copy_begin, copy_end));
			//std::cout << dist << std::endl;
			//std::cout << "print distance" << std::endl;
		}

		//std::cout << "hello?" << std::endl;

		main.insert(copy_end, current_orig);

		insertion_counter++;

		current_orig += 2;
		current_pend = next(current_pend, 1);
	}

	//dump evertyhing where it should be

	typedef typename GroupIterator::value_type					variable_type;
	typedef typename GroupIterator::iterator_type				iterator_type;
	typedef Container<variable_type, Alloc>						cache_cenas;

	cache_cenas cache;

	for (mainChainIterator it = main.begin(); it != main.end(); ++it)
	{
		iterator_type start = it->getIter();
		iterator_type finish = start;
		std::advance(finish, it->getSize());
		std::copy(start, finish, std::back_inserter(cache));
	}
	std::copy(cache.begin(), cache.end(), begin.getIter());

	//std::for_each(container.begin(), container.end(), print_number<T>);
	//std::cout << std::endl;

	//std::cout << "finished recursion loop"  << std::endl;
}

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
size_t	FordJohnsonSort(Container<T, Alloc>& container)
{
	size_t g_comp_count = 0;

	typedef typename Container<T, Alloc>::iterator iterator;

	iterator begin = container.begin();
	iterator end = container.end();

	_recursive(
		container,
		new_GroupIterator(begin, 1),
		new_GroupIterator(end, 1),
		g_comp_count
	);

	return (g_comp_count);
}

#endif
