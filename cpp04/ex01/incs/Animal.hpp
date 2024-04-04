/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 15:06:47 by codespace        ###   ########.fr       */
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
		Animal(const std::string& type);
		std::string type;
};


/*
	Protected parameterized constructor, Animal can't be instantiated with it but
	it is helpful for the derived class to add it to the initialized member list
*/

/*

	Contrary to cpp03, in this case we want animal pointers to be used
	polymorphically. Destructor must be virtual to make sure that it is
	overriden by the derived classes. If one calls delete on an animal pointer used
	to instantiate a Dog, it will call Dog's destructor before Animals
	Otherwise, if Dog has more members and more cleanup, only the Animal destructor will be called

	This will be particularly important in the Brain exercise where Cat's and Dogs must free
	their Brain
		-> without virtual destructor -> leaks :)

*/

#endif
