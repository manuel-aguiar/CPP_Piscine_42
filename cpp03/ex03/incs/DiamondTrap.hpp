/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 13:17:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

The base problem is the following:
   Base1       Base2
	|   		 |
 Derived1    Derived2
         \    /
         Monster

So, when monster refers to a a member variable that is originally in Base,
the compiler will through the ambiguous error:
	is it from Base1 or from Base2?

To remove the ambiguity, C++ introduces virtual inheritance which essentially guarantees
that that is only one instance of the each base class in case of multiple inheritance
in which some of the mid-derived classes inherit from the same base class.

But, now the problem becomes:

The Diamond Inheritance Problem -
          Base
         /    \
 Derived1    Derived2
         \    /
         Monster

Monster inherits from two classes that inherit from the same base class
Problems arise with the ambiguity of inheriting the same variables and functions
from two different sides.

On Derived1/2 we make them inherit from "virtual" Base
	So the same variables/functions are not created multiple times
However, if the Derived classes apply diifferent values to their member variables,
one must adjust the code to be sure that Monster is assigned the values to member variables
that we want


Essentially, we must manually assign the values we want, pretty much


Consclusion is, avoid this type of pattern, it generates more bad than good

*/

#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string& start_name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator= (const DiamondTrap& assign);

		void	whoAmI() const;

		//override
		void	my_stats() const;


	private:
		std::string	name;
};

/*
	//using	ScavTrap::attack;


	Interesting: regardless of the order of inheritance that you establish,
	DiamondTrap always inherits ScavTrap::attack and not FragTrap(ClapTrap)

	EVEN "using	FragTrap::attack", results in SCAVTRAP ATTACK being called
	even claptrap, it doesn't call claptrap

	Okay.... so "using" doesn't really do much in here
	If neither Scav/Frag try to override attack, no problem, one instance and
	that's what Diamond inherits -> directly from ClapTrap

	If both override:
		error: no unique final overrider for ‘virtual void ClapTrap::attack(const string&)’ in ‘DiamondTrap’

		The way to solve this is to explicitely override it in the DiamondTrap Class by
		doing another
		void attack() .... etc

	If only one overrides, that's the one that prevails.
	So ScavTrap overrides and that's what DiamondTrap gets,
	If you don't want that override, DiamondTrap needs to override the method itself, as in above

	Essentially, "using" does nothing here:

		"using" can be used in this context in case there is no diamond inheritance,
		as we tried to do in ScavTrap para "using" ClapTrap assignment operator

	


*/

#endif
