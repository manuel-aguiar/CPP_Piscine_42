/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:46 by codespace         #+#    #+#             */
/*   Updated: 2024/04/03 15:42:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Unnamed Constructor called" << std::endl;
	name = FRAG_START_NAME;
    hitpoints = FRAG_START_HP;
    energypoints = FRAG_START_EP;
    attackdamage = FRAG_START_ATTACK;
}

FragTrap::FragTrap(const std::string& start_name) : ClapTrap(start_name)
{
    std::cout << "FragTrap Named - " << start_name << " - Constructor called" << std::endl;
	/*
		this following line, in our case, is irrelevant, since name will
		be initialized to the name we want by the ClapTrap constructor
		we keep it for coherence, as it is an inherited member variable
	*/
	name = start_name;
    hitpoints = FRAG_START_HP;
    energypoints = FRAG_START_EP;
    attackdamage = FRAG_START_ATTACK;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap - " << name << " - Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap - " << name << " - Copy constructor called" << std::endl;
    if (this == &copy)
		return ;
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

FragTrap& FragTrap::operator= (const FragTrap& assign)
{
    std::cout << "ScavTrap - " << name << " - copy assignment operator called" << std::endl;
    if (this == &assign)
		return (*this);
	ClapTrap::operator=(assign);
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << ": give me a high five!!" << std::endl;
}
