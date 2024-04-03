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

	ClapTrap("_clap_name")  <- why not this in the member initializer list?
		because it will be overriden by Scav and Frag :)
		manually add "_clap_name" to clap name and that's it


	Fun fact.....
		ScavTrap::name += "_clap_name"; achieves exactly the same effect

	because.......... they are all the same variable under different names
	assembly is exactly the same.
	FragTrap::name would also work.

	The variables are not doubled, especially considering that we are using virtual inheritance
	and only one base class instance is created. The remaining constructors add to it, at best,
	if they add more variables.
	so, ClapTrap::name == ScavTrap::name == FragTrap::Name,
	The exception is DiamondTrap::name which refers to its own member variable
		Resolution of conflict is solved to the closest candidate fit, which in this case
		is its own variable and not the one inherited
		So, to refer to inherited, explicitely say where it comes from (ClapTrap::name, for instance)

*/

DiamondTrap::DiamondTrap() :	ClapTrap(), \
								ScavTrap(), \
								FragTrap(), \
								name(ClapTrap::name)

{
    std::cout << "DiamondTrap Unnamed Constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
	energypoints = ScavTrap::scav_starting_energy;
}

/*

	In virtual inheritance, the most derived class MUST CALL ALL OF ITS ANCESTORS DIRECTLY.
	If i ommitt the "ClapTrap(start_name + "_clap_name")" in the member initializer list,
	the compiler will call ClapTrap default constructor instead -> iit is the compiler that saves us
		I expected the ClapTrap parameter constructor to be called by ScavTrap's parameter constructor
		but upon compilation, default ClapTrap was called instead, meaning that it was the compiler
		who put it in there

	If you ommitt the ClapTrap(copy) in the copy constructor, the compiler straight up does not
	allow you to compile and that's it. To comply with the inheritance rules, the most derived
	must call all, itself. That is the way that virtual inheritance is translated to having

	only one instance of each ancestor at most: it is the grandchild that calls one of each,
	the middle family constructors only add things on top, themselves they don't call
	their respective ancestors.

	Meaning... in virtual inheritance, the compiler basically removes all constructor calls from your
	middle constructors.....? x'O

	Order matters, if you explicitely call ScavTrap constructor before ClapTrap, won't compile and
	will warn you that the order is incorrect because ClapTrap is base of ScavTrap

*/

/*
	redundant setting the name to += "_clap_name" but i had scav and clap overwriting
	the name variable in their construction.
	Anyways, unnavoidable that clap::name equals frag::name, same variable
*/

DiamondTrap::DiamondTrap(const std::string& start_name) :	ClapTrap(start_name + "_clap_name"), \
															ScavTrap(start_name), \
															FragTrap(start_name), \
															name(start_name)
{
    std::cout << "DiamondTrap Named - " << start_name << " - Constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
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
	ScavTrap::operator=(assign);
	FragTrap::operator=(assign);
    name = assign.name;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap - " << name << " - Destructor called" << std::endl;
}


void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap: i am - " << name << " -  and my clap name is - " << ClapTrap::name << std::endl;
}

void	DiamondTrap::my_stats() const
{
	std::cout << std::endl;
	std::cout << "DiamondTrap: i am - " << name << " -  and my clap name is - " << ClapTrap::name << std::endl;
	std::cout << "Here are my DiamondTrap Stats: " << name << std::endl;
	std::cout << "   HP: " << hitpoints << std::endl;
	std::cout << "   EP: " << energypoints << std::endl;
	std::cout << "   Attack Strength: " << attackdamage << std::endl;
	std::cout << std::endl;
}
