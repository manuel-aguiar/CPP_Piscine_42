/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnsonSort.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:25:10 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 14:12:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORDJOHNSON_TPP

# define FORDJOHNSON_TPP

# include "GroupIterator.hpp"
# include "IterFuncs.hpp"

# include <algorithm>
# include <iomanip>

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
	template <
		typename,
		typename
	> class Container,
	typename GroupIterator,
	class Alloc
> typename Container<GroupIterator, Alloc>::iterator
binary_search_count(typename Container<GroupIterator, Alloc>::iterator begin,
					typename Container<GroupIterator, Alloc>::iterator end,
					GroupIterator& value, size_t& g_comp_count)
{
	typedef typename Container<GroupIterator, Alloc>::iterator iterator;

	int dist = static_cast<int>(std::distance(begin, end));
	while (dist)
	{
		iterator mid = next(begin, dist / 2);
		g_comp_count++;
		if (*value > **mid)
			begin = next(mid, 1);
		else
			end = mid;
		dist = static_cast<int>(std::distance(begin, end));
	}
	return (end);
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

	for (GroupIterator iter(begin); iter != newEnd; iter += 2)
	{
		g_comp_count++;
		if (iter[0] > iter[1])
			iter_swap(iter, iter + 1);
	}


	_recursive(
		container,
		new_GroupIterator(begin, 2),
		new_GroupIterator(newEnd, 2),
		g_comp_count
	);

	typedef Container<GroupIterator, Alloc>                     		mainChainContainer;
	typedef typename mainChainContainer::iterator						mainChainIterator;

	typedef Container<int, Alloc>										pendChainContainer;
	typedef typename pendChainContainer::iterator						pendChainIterator;

	//separating main and pending
	mainChainContainer													main;
	pendChainContainer													pending;

	//second element is main chain, first is obviously lower given previous sorting
	//so, dump the first two elements
	main.push_back(begin);
	main.push_back(begin.next(1));

	//separating to main_chain, pending saves the relative position (re-alloc risk for vectors + iterator invalidation)
	//OG implementation used a std::list here to save iterators -> list iterators don't get invalidated
	//with insertions and deletions :)

	for (GroupIterator iter(begin + 2); iter != newEnd; iter += 2)
	{
		mainChainIterator temp = main.insert(main.end(), iter.next(1));
		pending.push_back(static_cast<int>(std::distance(main.begin(), temp)));
	}

	if (has_straggler)
		pending.push_back(static_cast<int>(std::distance(main.begin(),main.end())));

	GroupIterator 						current_orig = begin + 2;
	pendChainIterator  					current_pend = pending.begin();

	//insertion counter, compensate for displacement as elements are placed
	// less efficient than true Ford-Johnson..... but with vectors, saving iterators
	//wouldn't work as thhey get invalidated with previous insertions + potential realloc
	int insertion_counter = 0;

	int i = 0;
	while (true)
	{
		int distance = jacobsthal_diff[i];

		//filter according to jacobsthal numbers
		if (distance >= static_cast<int>(std::distance(current_pend, pending.end())))
			break ;

		GroupIterator 				move_orig 		= next(current_orig, distance * 2);
		pendChainIterator 			move_pend 		= next(current_pend, distance);

		do
		{
			move_orig -= 2;
			--move_pend;

			mainChainIterator copy_begin = main.begin();
			mainChainIterator copy_end = next(copy_begin, *move_pend + insertion_counter);

			mainChainIterator insertion_place =
			binary_search_count<Container, GroupIterator, Alloc>(
				copy_begin,
				copy_end,
				move_orig,
				g_comp_count
			);

			main.insert(insertion_place, move_orig);
			insertion_counter++;
		} while (move_pend != current_pend);

		current_orig = next(current_orig, distance * 2);
		current_pend = next(current_pend, distance);

		i++;
	}

	//empty the pending that were not placed before because jacobsthal numbers deemed inefficient
	while (current_pend != pending.end())
	{
		mainChainIterator copy_begin = main.begin();
		mainChainIterator copy_end = next(copy_begin, *current_pend + insertion_counter);

		mainChainIterator insertion_place =
		binary_search_count<Container, GroupIterator, Alloc>(
			copy_begin,
			copy_end,
			current_orig,
			g_comp_count
		);
		main.insert(insertion_place, current_orig);
		insertion_counter++;

		current_orig += 2;
		current_pend = next(current_pend, 1);
	}

	//dump evertyhing where it should be

	typedef typename GroupIterator::value_type					variable_type;
	typedef typename GroupIterator::iterator_type				iterator_type;
	typedef Container<variable_type, Alloc>						unpackedGroupIterators;

	unpackedGroupIterators unpacked;

	//copy all the elements associated with each single iterator, in order
	// to an "unpacked" container
	for (mainChainIterator it = main.begin(); it != main.end(); ++it)
	{
		iterator_type start = it->getIter();
		iterator_type finish = start;
		std::advance(finish, it->getSize());
		std::copy(start, finish, std::back_inserter(unpacked));
	}

	//dump unpack container to original container
	std::copy(unpacked.begin(), unpacked.end(), begin.getIter());

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
