/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 14:00:08 by codespace        ###   ########.fr       */
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

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
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
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& assign)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    name = assign.name;
    hitpoints = assign.hitpoints;
    energypoints = assign.energypoints;
    attackdamage = assign.attackdamage;
    return (*this);
}


void    ScavTrap::guardGate()
{
    this->gatekeeping = true;
    std::cout << "ScavTrap " << this->name << " is in Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (this->hitpoints <= 0)
	{
		std::cout << "ScavTrap "  << this->name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (this->energypoints == 0)
	{
		std::cout << "ScavTrap "  << this->name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		this->energypoints--;
		std::cout << "ScavTrap "  << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
	}
}
