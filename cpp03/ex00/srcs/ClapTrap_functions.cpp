/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:36:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

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
