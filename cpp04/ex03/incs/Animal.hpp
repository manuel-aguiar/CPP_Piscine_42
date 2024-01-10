/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 13:20:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	I would have made the public constructor as protected:
		accessible to descendents Cat/Dog but uninstantiable

	apparently as per the evaluation guide, the class must have a virtual function = 0;
	so there it is

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

#endif
