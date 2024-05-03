/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:00:35 by codespace         #+#    #+#             */
/*   Updated: 2024/05/03 10:30:58 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTCOMP_HPP

# define MERGEINSERTCOMP_HPP

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

#ifdef _ALL_IN
	# include <list>
	# include <set>
#endif

# define CERR(x) std::cerr << (x) << std::endl
# define VALID_CHARS "0123456789 \n\t\v\b"

template <
	typename T = unsigned int,
	template <
		typename,
		typename
	> class First = std::vector,
	template <
		typename,
		typename
	> class Second = std::deque
> class MergeInsertComp
{
	public:
		//Constructor / Destructor
		MergeInsertComp(int ac, char **av);
		~MergeInsertComp();

		
		//getters - not verbose, implemented right here
		size_t								getCount(void) const 		{return (_count);}
		const std::vector<unsigned int>&	getUnsorted(void) const 	{return (_unsorted);}
		PmergeMe<T, First>&					getFirst(void) const 		{return (_first);}
		PmergeMe<T, Second>&				getSecond(void) const 		{return (_second);}

	private:

		static const std::string			g_type_info[4];
		static const std::string			g_type_name[4];
		std::vector<T>						_unsorted;
		size_t								_count;

		PmergeMe<T, First>					_first;
		PmergeMe<T, Second>					_second;

		//parsing -> called from the Parameter Constructor
		template<
			class Inner
		> bool								parse(int ac, char **av, Inner& container);

		//Private default constructor, copy and assignment
		MergeInsertComp();
		MergeInsertComp(const MergeInsertComp& copy);
		MergeInsertComp& operator=(const MergeInsertComp& assign);

		#ifdef _ALL_IN
			std::multiset<T>				_set
		#endif	
};


#include "MergeInsertComp.tpp"

#endif
