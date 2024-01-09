/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 15:52:03 by codespace        ###   ########.fr       */
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

FragTrap& FragTrap::operator= (const FragTrap& assign)
{
    std::cout << "FragTrap - " << name << " - assignment operator called" << std::endl;
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
