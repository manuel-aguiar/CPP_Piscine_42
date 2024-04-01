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

/*

	Given our order of construction, essentially all member variables will become
	those of FragTrap.

	ClapTrap -> ScavTrap (override) -> FragTrap (override)

	so, we manually assign the ScavTrap energy points and on base class,
	Attack will be "using" ScavTrap

*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()

{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = ClapTrap::name;
	ClapTrap::name += "_clap_name";
	energypoints = ScavTrap::scav_starting_energy;
}

DiamondTrap::DiamondTrap(const std::string& start_name) :	ClapTrap(start_name + "_clap_name"), \
															ScavTrap(start_name), \
															FragTrap(start_name), \
															name(start_name)
{
    std::cout << "DiamondTrap Named - " << name << " - Constructor called" << std::endl;
	energypoints = ScavTrap::scav_starting_energy;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap - " << name << " - Copy constructor called" << std::endl;
    if (this == &copy)
		return ;
    *this = copy;
}

/*

	In this case i need the operator=explicitely because i have an extra member variable to copy
	and i cannot lose it :). still, i can call the operator= function of Scav, which in turn will be
	of Clap

	It would still work if i called Fragtrap operator= as both are equal to ClapTrap::operator=

	Of note, const static int scav_starting_energy is initialized at the beginning of the program,
	and is available to all classes, it is not a member variable we need to copy.

*/

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& assign)
{
    std::cout << "DiamondTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
		return (*this);
	ScavTrap::operator=(assign);
    name = assign.name;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap - " << name << " - Destructor called" << std::endl;
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: i am - " << name << " -  and my clap name is - " << ClapTrap::name << std::endl;
}
