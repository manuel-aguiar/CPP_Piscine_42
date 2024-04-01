/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:05:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		virtual void	makeSound(void) const;

    protected:
		std::string type;
};


/*

	This is about virtual functions. By making a function virtual,
	derived classes can override it. At runtime, the program will bind
	the correct call depending on what derived class is calling.

	If the function is not virtual, it cannot be overriden by derived classes
	If a derived is instantiated and has a declaration and definition,
	the derived method will be called.
	But via polymorphism  by having a base class pointer -> new,
	the base class method will be called if the function is not virtual

	If a class has a pure virtual function (virtual func() = 0), it becomes
	an abstract class and cannot be instantiated. Derived classes must
	define the function, otherwise they will be abstract as well
		this is syntax: virtual func() = 0;
		c++ way of doing interfaces

		Good example could be cub3d sprites:
			sprite as an abstract class with certain attributes and functions
			to change them (location, stats, etc)
			array of sprite pointers
			a sprite coukld be an enemy, a collectible, each would implement
			their own functions to change their own atributes
			code becomes simpler to write (compiler takes care of the machine code....)

*/

#endif
