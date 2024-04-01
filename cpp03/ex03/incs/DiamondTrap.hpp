/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 10:41:04 by codespace        ###   ########.fr       */
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

		using	ScavTrap::attack;
		void	whoAmI();

	private:
		std::string	name;
};



#endif
