/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 08:37:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap() : name(START_NAME) , hitpoints(START_HP), \
						energypoints(START_EP), attackdamage(START_ATTACK)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& start_name) : name(start_name) , hitpoints(START_HP), \
													energypoints(START_EP), attackdamage(START_ATTACK)
{
	std::cout << "ClapTrap Name Constructor called: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap - " << name << " - Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap - " << name << " - copy constructor called" << std::endl;
	if (this == &copy)
		return ;
	*this = copy;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& assign)
{
	std::cout << "ClapTrap - " << name << " - copy assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	name = assign.name;
	hitpoints = assign.hitpoints;
	energypoints = assign.energypoints;
	attackdamage = assign.attackdamage;
	return (*this);
}
