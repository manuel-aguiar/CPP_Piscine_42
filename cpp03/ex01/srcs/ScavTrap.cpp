/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 09:15:44 by codespace        ###   ########.fr       */
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
}

/*

	Assignment operator is ommitted here given that we are "using" ClapTrap::operator=

*/

void    ScavTrap::guardGate()
{
    gatekeeping = true;
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
