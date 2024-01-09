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
	name = "tretas";
	hitpoints = FragTrap::hitpoints;
	energypoints = ScavTrap::energypoints;
	attackdamage = FragTrap::attackdamage;
}

DiamondTrap::DiamondTrap(const std::string& start_name) : ClapTrap(start_name + "_clap_name"), ScavTrap(start_name), FragTrap(start_name), name(start_name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
	hitpoints = FragTrap::hitpoints;
	energypoints = ScavTrap::energypoints;
	attackdamage = FragTrap::attackdamage;
}

//copy


//copy assign

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap - " << name << " - Destructor called" << std::endl;
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: i am - " << name << " -  and my clap name is - " << ClapTrap::name << std::endl;
}
