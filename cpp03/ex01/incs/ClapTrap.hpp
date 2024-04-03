/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 15:11:09 by codespace        ###   ########.fr       */
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
			it goes to the vtable of the derived class and calls the derived destructor

		More a particularity of abstract classes
		In our case, claptrap is supposed to be instantiated on its own

		Using a virtual destructor uses more memory (vtable, we are already making attack virtual)
		and implies runtime polymorphism which can be more expensive computationally
		Don't do this, still a good experiment

		If the base class is instantiated, the destructor will be normally called as usual,
		it is just unnecessary overhead to make the destructor virtual if
		the class is going to be instantiated normally

		Rule of thumb: if a class has a virtual function, add a virtual destructor, just in case,
		no big extra cost and allows for polymorphism. Virtual function usually means that
		a class is to be used a base class for something else
			Cost is low, vtable is per-class and not per instance, actual object remains the same in size,
			it is the vtable that grows


	Destruction, in general
	We don't see it, but the compiler infuses code to ensure that destruction takes place in the correct order
	(most derived, to most base, inversely to construction).
	In reality, it is as if we wrote:
	Derived::~Derived()
	{
		Base::~Base;
	}
	So, if you have a virtual destructor, Derived' destructor will be called via Derived vtable, then Base::~Base
	is called via Base vtable, BUT IT IS CALLED FROM INSIDE THE DERIVED DESTRUCTOR
	As with all virtual functions, if the derived provides an override, it becomes the closest candidate fit in
	the inheritance chain.

	If Derived doesn't provide an override for the Base virtual destructor, compiler will probably infuse a default
	destructor....
	Do it, nevertheless

*/


#endif
