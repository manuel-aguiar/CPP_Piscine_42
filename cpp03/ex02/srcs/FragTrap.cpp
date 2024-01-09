/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:59:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Unnamed Constructor called" << std::endl;
	name = FRAG_START_NAME;
    hitpoints = FRAG_START_HP;
    energypoints = FRAG_START_EP;
    attackdamage = FRAG_START_ATTACK;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap Named - " << name << " - Constructor called" << std::endl;
    hitpoints = FRAG_START_HP;
    energypoints = FRAG_START_EP;
    attackdamage = FRAG_START_ATTACK;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

FragTrap& FragTrap::operator= (const FragTrap& assign)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    name = assign.name;
    hitpoints = assign.hitpoints;
    energypoints = assign.energypoints;
    attackdamage = assign.attackdamage;
    return (*this);
}


void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << ": give me a high five!!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (this->hitpoints <= 0)
	{
		std::cout << "FragTrap "  << this->name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (this->energypoints == 0)
	{
		std::cout << "FragTrap "  << this->name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		this->energypoints--;
		std::cout << "FragTrap "  << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
	}
}
