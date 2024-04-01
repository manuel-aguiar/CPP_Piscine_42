/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:57:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	I would have made the public constructor as protected:
		accessible to descendents Cat/Dog but uninstantiable

	apparently as per the evaluation guide, the class must have a virtual function = 0;
	so there it is

	It must have a virtual function such that it is not instantiable
		virtual func() = 0 is C++ syntax
		Any derived class that doesn't present a declaration and implementation for
		such a function, will become an abstract class as well.

*/

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal
{
    public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator= (const Animal& assign);

		const std::string&	getType(void) const;

		virtual void	makeSound(void) const = 0;

    protected:
		std::string type;
};

/*
	random note:

	lvalue = has location in memory, persistent
		you do math and save the value somewhere
	rvalue = temporary that is discarded, example middle math evaluation
	x =	1 + 1 + 1, 2 + 1 (2 is discarded), 3 assigned to x

*/

#endif
