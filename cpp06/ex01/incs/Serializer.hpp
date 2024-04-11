/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:41:56 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 11:41:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

class Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& assign);
};


/*

	https://www.youtube.com/watch?v=SmlLdd1Q2V8

	https://gist.github.com/shafik/848ae25ee209f698763cffee272a58f8

	C-style cast starts as a const_cast, then static_cast + const_cast,
	then reinterpret_cast + const_cast.

	C-style casts are therefore super powerfull, maybe too much

	-Wold-style-cast


	Desincentivized to use C-style casts in general:
		harder to find bugs
		underlying behavior means one doesn't know exactly which one
		cast was used
		no warnings
*/

#endif
