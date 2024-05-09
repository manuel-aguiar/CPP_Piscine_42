/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnsonSort.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:59 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 09:38:40 by codespace        ###   ########.fr       */
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
class FordJohnson
{
	public:
		FordJohnson() {};
		~FordJohnson() {};

		size_t operator()(Container<T, Alloc>& container)
			{return (FordJohnsonSort(container));}

	private:
		FordJohnson(const FordJohnson& copy) {};
		FordJohnson& operator=(const FordJohnson& assign) {};
};

#include "../tpp/FordJohnsonSort.tpp"

#endif
