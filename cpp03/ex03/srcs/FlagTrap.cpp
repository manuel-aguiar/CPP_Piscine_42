/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:24:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
    std::cout << "FlagTrap Unnamed Constructor called" << std::endl;
	name = FLAG_START_NAME;
    hitpoints = FLAG_START_HP;
    energypoints = FLAG_START_EP;
    attackdamage = FLAG_START_ATTACK;
}

FlagTrap::FlagTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FlagTrap Named - " << name << " - Constructor called" << std::endl;
    hitpoints = FLAG_START_HP;
    energypoints = FLAG_START_EP;
    attackdamage = FLAG_START_ATTACK;
}

FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap Destructor called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& copy) : ClapTrap(copy)
{
    std::cout << "FlagTrap Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

FlagTrap& FlagTrap::operator= (const FlagTrap& assign)
{
    std::cout << "FlagTrap assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    name = assign.name;
    hitpoints = assign.hitpoints;
    energypoints = assign.energypoints;
    attackdamage = assign.attackdamage;
    return (*this);
}


void    FlagTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << this->name << ": give me a high five!!" << std::endl;
}

void	FlagTrap::attack(const std::string& target)
{
	std::cout << "FlagTrap " << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (this->hitpoints <= 0)
	{
		std::cout << "FlagTrap "  << this->name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (this->energypoints == 0)
	{
		std::cout << "FlagTrap "  << this->name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		this->energypoints--;
		std::cout << "FlagTrap "  << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
	}
}
