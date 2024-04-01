/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:14 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:43:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define START_HP 10
#define START_EP 10
#define START_ATTACK 0
#define START_NAME "Unnamed"

class ClapTrap
{
    public:
		ClapTrap();
		ClapTrap(const std::string& start_name);
		~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator= (const ClapTrap& assign);

		void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);
		void    my_stats( void ) const;

    private:
		std::string name;
		unsigned int hitpoints;
		unsigned int energypoints;
		unsigned int attackdamage;
};

/*
	How come the copy constructor (assignment operator) have access to the copies' private members
	without using getters in the function implementation?

	Member  functions of a class have access to all information about an instance of an aobject
	of said class if they have a reference(pointer) to it.

	Copy constructor is a public member function of a class, if you pass an object from which you want to copy,
	the copy constructor can access it.
	If you have 2 characters, one attacks the other, and the function is passed a reference to "other",
	the function can take the private attack value and reduce the victims lifepoints
*/



#endif
