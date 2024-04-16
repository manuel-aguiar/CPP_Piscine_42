/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 13:28:32 by codespace        ###   ########.fr       */
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

//astein
# define CLR_RED 	"\033[1;31m"
# define CLR_BLUE 	"\033[1;34m"
# define CLR_CYAN 	"\033[1;36m"
# define CLR_PINK 	"\033[1;35m"
# define CLR_RESET 	"\033[0m"
# define CLR_GRN 	"\033[32m"

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
