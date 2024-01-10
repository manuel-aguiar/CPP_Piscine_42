/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 12:44:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	protected constructor so nobody can instantiate it from outside but
	descendents can use it

*/

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal
{
    public:

		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator= (const Animal& assign);

		const std::string&	getType(void) const;

		virtual void	makeSound(void) const;

    protected:
		Animal();
		std::string type;
};

#endif
