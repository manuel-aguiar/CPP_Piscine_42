/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:30 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 10:46:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

# include <string>
# include <iostream>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		// my own, for visualization, cleaner than static cast to Character *
		virtual void print_stats(void) const = 0;
};

/*

	c++ "interfaces" (not really a class type in c++), usually don't have any non-static
	member variables, so the "constructor is not needed"
		-> in reality, construction is definitely needed since interfaces
		have virtual functions, therefore most compilers will infuse code
		to construct their vtables

		We, the user, have nothing to implement, but under the hood, there is stuff going on

	The exercise demands classes that implement interfaces, not our interface implementation

	Under the hood, since the interface itself is not instantiated, virtual destructor
	will always be called -> but the derived destructor must call for the interface
	destructor to get rid of the interface-in-derived vtable (and of course, its vpointer)

	AMateria, is an abstract class but has non-static member variables, so it needs a constructor


	EXCEPTIONS:

		the interface could declarre a static member variable, in which case a constructor
		probably makes sense

*/

#endif
