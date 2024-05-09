/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterFuncs.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:01:09 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 18:29:49 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORFUNCS_HPP

# define ITERATORFUNCS_HPP

#include <iterator>

template <
	class Iterator
>
Iterator	next(Iterator& iter, int index);

template <
	class Iterator
>
Iterator	prev(Iterator& iter, int index);

#include "../tpp/IterFuncs.tpp"

#endif
