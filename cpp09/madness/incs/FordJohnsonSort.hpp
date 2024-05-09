/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnsonSort.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:59 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 10:26:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORDJOHNSON_HPP

# define FORDJOHNSON_HPP

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


/* FordJohnson functor class, just for fun*/

template <
	template <
		typename,
		typename
	> class Container,
	class T,
	class Alloc
>
class FordJohnsonFunctor
{
	public:
		FordJohnsonFunctor() {};
		~FordJohnsonFunctor() {};
		FordJohnsonFunctor(const FordJohnsonFunctor& copy) {(void)copy;};
		FordJohnsonFunctor& operator=(const FordJohnsonFunctor& assign) {(void)assign; return(*this);};

		size_t operator()(Container<T, Alloc>& container)
			{return (FordJohnsonSort(container));}
};

#include "../tpp/FordJohnsonSort.tpp"

#endif
