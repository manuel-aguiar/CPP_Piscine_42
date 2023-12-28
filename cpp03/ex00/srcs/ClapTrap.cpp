/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:42:27 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:42:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl;
    this->name = START_NAME;
    this->hitpoints = START_HP;
    this->energypoints = START_EP;
    this->attackdamage = START_ATTACK;
}

ClapTrap::ClapTrap(const std::string& name) : name(name)
{
    std::cout << "Name Constructor called: " << name << std::endl;
    this->hitpoints = START_HP;
    this->energypoints = START_EP;
    this->attackdamage = START_ATTACK;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    if (this == &copy)
        return ;
    this->hitpoints = copy.hitpoints;
    this->energypoints = copy.energypoints;
    this->attackdamage = copy.attackdamage;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& assign)
{
    if (this == &assign)
        return (*this);
    this->hitpoints = assign.hitpoints;
    this->energypoints = assign.energypoints;
    this->attackdamage = assign.attackdamage;
    return (*this);
}


void    ClapTrap::attack(const std::string& target)
{
    std::cout << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
    if (this->hitpoints <= 0)
    {
        std::cout << this->name << " is dead, can't attack" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, attack failed" << std::endl;
    }
    else
    {
        this->energypoints--;
        std::cout << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " is taking damage, checking stats..." << std::endl;
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, attack failed" << std::endl;
    }
    else
    {
        this->hitpoints = (this->hitpoints - amount) * (this->hitpoints > amount);
        std::cout << this->name << " takes " << amount << " of damage! " << std::endl;
    }
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is dead, no HP left" << std::endl;
        return ;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->name << " wants to repare, checking stats..." << std::endl;
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, repair failed" << std::endl;
    }
    else
    {
        this->energypoints--;
        this->hitpoints += amount;
        std::cout << this->name << " repairs " << amount << " points! " << std::endl;
    }
}

void    ClapTrap::my_stats( void )
{
    std::cout << std::endl;
    std::cout << "Stats: " << this->name << std::endl;
    std::cout << "   HP: " << this->hitpoints << std::endl;
    std::cout << "   EP: " << this->energypoints << std::endl;
    std::cout << "   Attack Strength: " << this->attackdamage << std::endl;
    std::cout << std::endl;
}
