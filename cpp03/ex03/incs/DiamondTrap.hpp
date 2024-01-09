/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 17:08:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

This is called the Diamond Inheritance Problem -
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
However, then if the Derived change values differently, we need to know how to assign them
on "Monster" with the correct values we desire

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
