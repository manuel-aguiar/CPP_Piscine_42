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

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()

{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = ClapTrap::name;
	ClapTrap::name += "_clap_name";
	energypoints = ScavTrap::scav_starting_energy;
}

DiamondTrap::DiamondTrap(const std::string& start_name) : ClapTrap(start_name + "_clap_name"), \
														ScavTrap(start_name), FragTrap(start_name), \
														name(start_name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
	energypoints = ScavTrap::scav_starting_energy;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap - " << name << " - Copy constructor called" << std::endl;
    if (this == &copy)
		return ;
    *this = copy;
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
