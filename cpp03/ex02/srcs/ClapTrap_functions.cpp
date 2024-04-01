/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 08:40:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 09:53:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap: " << name << " wants to attack " \
	<< target << ", checking energy..." << std::endl;
	if (hitpoints <= 0)
	{
		std::cout << name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (energypoints == 0)
	{
		std::cout << name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		energypoints--;
		std::cout << name << " attacks " << target << ", causing " << attackdamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " is taking damage, checking stats..." << std::endl;
	if (hitpoints == 0)
	{
		std::cout << name << " is already dead" << std::endl;
		return ;
	}
	if (energypoints == 0)
	{
		std::cout << name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		hitpoints = (hitpoints - amount) * (hitpoints > amount);
		std::cout << name << " takes " << amount << " of damage! " << std::endl;
	}
	if (hitpoints == 0)
	{
		std::cout << name << " is dead, no HP left" << std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " wants to repare, checking stats..." << std::endl;
	if (hitpoints == 0)
	{
		std::cout << name << " is already dead" << std::endl;
		return ;
	}
	if (energypoints == 0)
	{
		std::cout << name << " has no energy left, repair failed" << std::endl;
	}
	else
	{
		energypoints--;
		hitpoints += amount;
		std::cout << name << " repairs " << amount << " points! " << std::endl;
	}
}

void	ClapTrap::my_stats( void ) const
{
	std::cout << std::endl;
	std::cout << "Stats: " << name << std::endl;
	std::cout << "   HP: " << hitpoints << std::endl;
	std::cout << "   EP: " << energypoints << std::endl;
	std::cout << "   Attack Strength: " << attackdamage << std::endl;
	std::cout << std::endl;
}
