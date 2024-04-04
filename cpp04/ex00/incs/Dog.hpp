/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:30 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 14:44:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator= (const Dog& assign);

		void	makeSound(void) const;
};


/*

	Interesting test:
	Animal *ptr = new Dog;

	ptr->a_function_only_declared_and_defined_at_Dog();

	This won't compile. "a_function_only_declared_and_defined_at_Dog" is not a method of Animal

	However, interestingly (or not, polymorphism)

	Animal *ptr = new Dog;

	ptr->a_function_declared_at_animal_overriden_by_Dog_and_override_changes_non_inherited_variables();

	This will compile, and work.
	BECAUSE -> this pointer adjustment using the animal-in-dog vtable's top offset
		this offset, calculated at the beginning of the program, specifies how far is the Dog's
		first member variable from the Animal-in-Dog's first member variable

	The function will be called not with Dog's Animal, but with Dog's, to match the prototype
	declared by Dog

	So... after dynamic dispatch, there is no Animal, only Dog -> it can change any of its member
	variables, either inherited or not :)
	#magic

*/

#endif
