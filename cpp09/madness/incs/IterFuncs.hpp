/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterFuncs.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:01:09 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 12:09:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORFUNCS_HPP

# define ITERATORFUNCS_HPP

#include <iterator>

template <
	typename Iterator
>
Iterator	next(Iterator& iter, int index);

template <
	typename Iterator
>
Iterator	prev(Iterator& iter, int index);

#include "../tpp/IterFuncs.tpp"

#endif
