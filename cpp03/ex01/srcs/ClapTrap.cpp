/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 09:19:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap() : name(CLAP_START_NAME) , hitpoints(CLAP_START_HP), \
						energypoints(CLAP_START_EP), attackdamage(CLAP_START_ATTACK)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& start_name) : name(start_name) , hitpoints(CLAP_START_HP), \
													energypoints(CLAP_START_EP), attackdamage(CLAP_START_ATTACK)
{
	std::cout << "ClapTrap Name Constructor called: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap - " << name << " - Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), hitpoints(copy.hitpoints), \
										energypoints(copy.energypoints), attackdamage(copy.attackdamage)
{
	std::cout << "ClapTrap - " << name << " - copy constructor called" << std::endl;
	if (this == &copy)
		return ;
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
