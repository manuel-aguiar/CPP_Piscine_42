/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:17:00 by codespace        ###   ########.fr       */
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
		used to obtain runtime polymorphism (late binding)
		still, the compiler may optimize this and resolve at compile time :)


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


	"protected" keyword:

	Virtual destructor:
		not the point of the exercise but essentially we are allowing for the
		free of a base class pointer to call the derived destructor
		and avoiding undeefined behaviour

		More a particularity of abstract classes
		In our case, claptrap is supposed to be instantiated on its own

		Using a virtual destructor uses more memory (vtable, we are already making attack virtual)
		and implies runtime polymorphism which can be more expensive computationally
		Don't do this, still a good experiment

		If the base class is instantiated, the destructor will be normally called as usual,
		it is just unnecessary overhead to make the destructor virtual if
		the class is going to be instantiated normally

*/


#endif
