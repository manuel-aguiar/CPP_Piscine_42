/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:57:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Unnamed Constructor called" << std::endl;
    //hitpoints = SCAV_START_HP;
    //energypoints = SCAV_START_EP;
    //attackdamage = SCAV_START_ATTACK;
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
    std::cout << "ScavTrap Destructor called" << std::endl;
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

