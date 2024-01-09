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

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = "tretas";
	hitpoints = ClapTrap::hitpoints;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), name(name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
	hitpoints = ClapTrap::hitpoints;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap - " << name << " - Destructor called" << std::endl;
}
