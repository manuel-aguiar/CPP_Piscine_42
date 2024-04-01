/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 08:46:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define CLAP_START_NAME "Unnamed"
#define CLAP_START_HP 10
#define CLAP_START_EP 10
#define CLAP_START_ATTACK 0

class ClapTrap
{
    public:
		ClapTrap();
		ClapTrap(const std::string& start_name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator= (const ClapTrap& assign);

		virtual void    attack(const std::string& target);
		void    		takeDamage(unsigned int amount);
		void    		beRepaired(unsigned int amount);
		void    		my_stats( void ) const;

    protected:
		std::string name;
		unsigned int hitpoints;
		unsigned int energypoints;
		unsigned int attackdamage;
};

/*

	A virtual function is a non-static member function than can be overriden
	by derived classes


	C++ classs vs struct:
	https://www.geeksforgeeks.org/structure-vs-class-in-cpp/

	0) syntax, class/struct, of course

	1) encapsulation:
		class: members are PRIVATE by default
		struct: members are PUBLIC by default
	2) Naming:
		class instance is called OBJECT
		struct instance is called STRUCT VARIABLE


	Inheritance is possible with both :0
*/


#endif
