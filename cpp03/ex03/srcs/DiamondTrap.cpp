/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 17:13:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = DIAM_START_NAME;
    hitpoints = DIAM_START_HP;
    energypoints = DIAM_START_EP;
    attackdamage = DIAM_START_ATTACK;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
    hitpoints = DIAM_START_HP;
    energypoints = DIAM_START_EP;
    attackdamage = DIAM_START_ATTACK;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& assign)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    name = assign.name;
    hitpoints = assign.hitpoints;
    energypoints = assign.energypoints;
    attackdamage = assign.attackdamage;
    return (*this);
}


void    DiamondTrap::guardGate()
{
    this->gatekeeping = true;
    std::cout << "DiamondTrap " << this->name << " is in Gate Keeper mode." << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap " << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (this->hitpoints <= 0)
	{
		std::cout << "DiamondTrap "  << this->name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (this->energypoints == 0)
	{
		std::cout << "DiamondTrap "  << this->name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		this->energypoints--;
		std::cout << "DiamondTrap "  << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
	}
}
