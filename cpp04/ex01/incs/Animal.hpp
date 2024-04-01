/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:19:45 by codespace        ###   ########.fr       */
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

	Contrary to cpp03, in this case we want animal pointers to be used
	polymorphically. Destructor must be virtual to make sure that it is
	overriden by the derived classes. If one calls delete on an animal pointer used
	to instantiate a Dog, it will call Dog's destructor before Animals
	Otherwise, if Dog has more members and more cleanup, only the Animal destructor will be called

	This will be particularly important in the Braine xercise where Cat's and Dogs must free
	their Brain

*/

#endif
