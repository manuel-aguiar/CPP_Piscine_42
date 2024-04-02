/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 12:21:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*

	In all constructors, one must specifically call the base class constructor
	without that, ScavTrap can only be instantiated with the member variables
	it has itself declared, in this case: none

	ScavTrap::ScavTrap(const std::string& start_name) : name (start_name)
	"error: class ‘ScavTrap’ does not have any field named ‘name’"
	Because at instantiation, we did not call for the pre-construction of
	the inherited member variables

	Now, we can call the constructor to instantiate the variables, but can we
	, in order, pre-assign a value to for instance "name" which was inherited and, by order,
	already constructed?

	ScavTrap::ScavTrap(const std::string& start_name) : ClapTrap(start_name), name("batata")
	" error: class ‘ScavTrap’ does not have any field named ‘name’"

	Nop! When the expression is evaluated, ScavTrap still doesn't have any member variable
	called "name".

	We can only change that inside the body of the constructor, when the variables
	have already been initialized. "Initialized?" Yes, test:
		class ScavTrap
		{
			...
			private:
				ClapTrap clap;
		}

	constructor:
		clap = ClapTrap(start_name)

	It will call a ClapTrap parameter constructor for start_name (rvalue),
	then call the COPY ASSIGNMENT OPERATOR unnamed for Scavtrap::clap
		which means that  Scavtrap::clap is already initialized when we get to constructor function body

	This pre-construction is called: MEMBER INITIALIZER LIST
		This is where we pre-specify, before the body of the constructor, the construction
		of inherited member variables and assign references upon instantiation

	This is way the values for scavtrap have to be assigned in the function body and not
	in the member initializer list:
		at that expression evaluiation moment, there are no such variables present in the ScavTrap class

	I added another member variable to ScavTrap, that one i can put in the member initalizer list
	since, at evaluation, that member is indeed already part of ScavTrap with no pre-requistes

*/

ScavTrap::ScavTrap() : ClapTrap(), gatekeeping(false)
{
    std::cout << "ScavTrap Unnamed Constructor called" << std::endl;
	name = SCAV_START_NAME;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::ScavTrap(const std::string& start_name) : ClapTrap(start_name), gatekeeping(false)
{
    std::cout << "ScavTrap Named - " << start_name << " - Constructor called" << std::endl;

	/*
		this following line, in our case, is irrelevant, since name will
		be initialized to the name we want by the ClapTrap constructor
		we keep it for coherence, as it is an inherited member variable
	*/
	name = start_name;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap - " << name << " - Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

/*

	I initially considered not implementing the operator= overload since the structure
	of Base and Derive is internally the same:
		vtable pointer (because Claptrap has a virtual destructor and virtual attack())
		member variables, to which Derived adds non

	However, this creates problems since, if i was to add more variables to Derived
	"using ClapTrap::operator=" would only copy the members that are already present
	in the Base class and not the rest

	So, for maintanability and retaining flexibility for further features, it is best
	to declare and define an operateor= overload for the Derived class, even if it
	at first calls the Base assignment operator

*/

ScavTrap& ScavTrap::operator= (const ScavTrap& assign)
{
    std::cout << "ScavTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
		return (*this);
	ClapTrap::operator=(assign);
	gatekeeping = assign.gatekeeping;
    return (*this);
}

void    ScavTrap::guardGate()
{
	gatekeeping = true;
    std::cout << "ScavTrap " << name << " is in Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name << " wants to attack " << target << ", checking energy..." << std::endl;
	if (hitpoints <= 0)
	{
		std::cout << "ScavTrap "  << name << " is dead, can't attack" << std::endl;
		return ;
	}
	if (energypoints == 0)
	{
		std::cout << "ScavTrap "  << name << " has no energy left, attack failed" << std::endl;
	}
	else
	{
		energypoints--;
		std::cout << "ScavTrap "  << name << " attacks " << target << ", causing " << attackdamage << " points of damage!" << std::endl;
	}
}
