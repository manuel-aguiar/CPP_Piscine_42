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

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = ClapTrap::name;
	energypoints = SCAV_START_EP;
}

DiamondTrap::DiamondTrap(const std::string& start_name) : ClapTrap(start_name + "_clap_name"), ScavTrap(start_name), FragTrap(start_name), name(start_name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
	energypoints = SCAV_START_EP;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap - " << name << " - Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& assign)
{
    std::cout << "DiamondTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    name = assign.name;
    hitpoints = assign.hitpoints;
    energypoints = assign.energypoints;
    attackdamage = assign.attackdamage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap - " << name << " - Destructor called" << std::endl;
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: i am - " << name << " -  and my clap name is - " << ClapTrap::name << std::endl;
}

void	DiamondTrap::diamond_stats( void ) const
{
	std::cout << std::endl;
	std::cout << "Stats: " << name << std::endl;
	std::cout << "   HP: " << hitpoints << std::endl;
	std::cout << "   EP: " << energypoints << std::endl;
	std::cout << "   Attack Strength: " << attackdamage << std::endl;
	std::cout << std::endl;
}
