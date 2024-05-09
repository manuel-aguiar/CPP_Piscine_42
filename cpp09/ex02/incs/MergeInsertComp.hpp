/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:00:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 11:18:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTCOMP_HPP

# define MERGEINSERTCOMP_HPP

# include "FordJohnsonSort.hpp"
# include "PmergeMe.hpp"

# include <string>
# include <algorithm>
# include <sstream>
# include <cerrno>
# include <limits>
# include <cstdio>
# include <typeinfo>
# include <iostream>



//sequence
# include <vector>
# include <deque>
# include <list>

#ifdef _ALL_IN
	# include <set>
#endif

template <
	typename T = unsigned int,
	template <
		typename,
		typename
	> class First = std::vector,
	template <
		typename,
		typename
	> class Second = std::deque,
	template <
		template <
			typename,
			typename
		> typename,
		class,
		class
	> class SortingFunction = FordJohnsonFunctor,
	class Allocator = std::allocator<T>
> class MergeInsertComp
{
	public:
		//Constructor / Destructor
		MergeInsertComp(int ac, char **av);
		~MergeInsertComp();


		//getters - not verbose, implemented right here
		PmergeMe<T, First, SortingFunction, Allocator>&					getFirst(void) const 		{return (_first);}
		PmergeMe<T, Second, SortingFunction, Allocator>&				getSecond(void) const 		{return (_second);}

	private:

		PmergeMe<T, First, SortingFunction, Allocator>					_first;
		PmergeMe<T, Second, SortingFunction, Allocator>					_second;

		//parsing -> called from the Parameter Constructor
		/*template<
			class Inner
		> bool								parse(int ac, char **av, Inner& container);*/

		void								run(int ac, char **av);

		//Private default constructor, copy and assignment
		MergeInsertComp();
		MergeInsertComp(const MergeInsertComp& copy);
		MergeInsertComp& operator=(const MergeInsertComp& assign);
};


#include "../tpp/MergeInsertComp.tpp"

#endif
