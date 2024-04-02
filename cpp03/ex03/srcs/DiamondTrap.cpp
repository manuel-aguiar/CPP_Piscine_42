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

	in ALL CONSTRUCTORS, the compiler will check that the order by which we call the
	inherited constructors is maintained with respect to what we defined in the header file:

	"class DiamondTrap : public ScavTrap, public FragTrap"


	in this case, "name" is allso a member  variable of class DiamondTrap in itself
	so we can add it to the member initializer list before the function body

*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()

{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	name = ClapTrap::name;
	ClapTrap::name += "_clap_name";
	energypoints = ScavTrap::scav_starting_energy;
}

DiamondTrap::DiamondTrap(const std::string& start_name) :
															ScavTrap(start_name), \
															FragTrap(start_name), \
															name(start_name)
{
    std::cout << "DiamondTrap Named - " << start_name << " - Constructor called" << std::endl;
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

	In this case, an operator= overload for DiamondTrap is unavoidable since it adds a member variable
	on top of the inherited member variables

	In any case, to allow further growth of the its superclasses, we call the assignment operators
	in the order of inheritance we specified in DiamondTrap.hpp


*/

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& assign)
{
    std::cout << "DiamondTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
		return (*this);
	FragTrap::operator=(assign);
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
