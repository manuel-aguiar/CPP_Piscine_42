/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 11:33:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Unnamed Constructor called" << std::endl;
	name = SCAV_START_NAME;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::ScavTrap(const std::string& start_name) : ClapTrap(start_name)
{
    std::cout << "ScavTrap Named - " << name << " - Constructor called" << std::endl;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap - " << name << " - Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

/*

	I initially considered not implementing the operator= overload since the structure
	of Base and Derive is internally the same:
		vtable pointer (because Claptrap has a virtual destructor and virtual attack())
		member variables, to which Derived adds non

	However, this creates problems since, if i was to add more variables to Derived
	"using ClapTrap::operator=" would only copy the members that are already present
	in the Base class and not the rest

	So, for maintanability and retaining flexibility for further features, it is best
	to declare and define an operateor= overload for the Derived class, even if it
	at first calls the Base assignment operator

*/

ScavTrap& ScavTrap::operator= (const ScavTrap& assign)
{
    std::cout << "ScavTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
		return (*this);
	ClapTrap::operator=(assign);
    return (*this);
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is in Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (hitpoints <= 0)
	{
		std::cout << "ScavTrap "  << name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (energypoints == 0)
	{
		std::cout << "ScavTrap "  << name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		energypoints--;
		std::cout << "ScavTrap "  << name << " attacks " << target << ", causing " << attackdamage << " points of damage!" << std::endl;
	}
}
