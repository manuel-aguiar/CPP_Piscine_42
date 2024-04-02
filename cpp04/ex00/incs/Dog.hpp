/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:30 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 14:06:34 by codespace        ###   ########.fr       */
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

	This won't compile. because the base class has no member SomeBS
	This mechanism can only be used with functions that are declared at Base class
	Derived vtable (and memory layout) will start the same as the Base class after
	which, partticular features of Derived are added.
	So, pointer arithmatic between the two vtables is exactly the same.
	The crucial part (dynamic dispatch) is dereferencing the correct vtable pointer:
	either Base vtable_ptr or the correct Derived vtable_ptr
		The compiler won't allow a dereferencing of a function pointer of a size outside
		of Base's own vtable size-> what matters is that the vtable_ptr that is dereferenced
		is not Base's but Derived's

	So, its polymorphism / encapsulation  in which the internals are concealed from the
	user but the user is still constrained by the functions available from the Base class
*/

#endif
