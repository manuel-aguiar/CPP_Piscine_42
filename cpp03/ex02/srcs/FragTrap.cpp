/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 09:52:33 by codespace        ###   ########.fr       */
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

FragTrap::FragTrap(const std::string& start_name) : ClapTrap(start_name)
{
    std::cout << "FragTrap Named - " << name << " - Constructor called" << std::endl;
    hitpoints = FRAG_START_HP;
    energypoints = FRAG_START_EP;
    attackdamage = FRAG_START_ATTACK;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap - " << name << " - Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap - " << name << " - Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackdamage = copy.attackdamage;
}

/*

	Assignment operator is ommitted here given that we are "using" ClapTrap::operator=

*/

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << ": give me a high five!!" << std::endl;
}
