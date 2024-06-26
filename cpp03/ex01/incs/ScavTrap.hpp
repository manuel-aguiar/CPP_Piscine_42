/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 15:19:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


#define SCAV_START_NAME "Unnamed"
#define SCAV_START_HP 100
#define SCAV_START_EP 50
#define SCAV_START_ATTACK 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& start_name);
		~ScavTrap();
		ScavTrap(const ScavTrap& copy);

		ScavTrap& operator= (const ScavTrap& assign);

		void	attack(const std::string& target); // override;
		void    guardGate();

	private:
		bool		gatekeeping;

};

/*

	Assignment operator is not inherited but the compiler will
	provide a definition of the derived class in case the class
	does not provide it itself

	Ommiting, the operator= called will be compiler definition:
		https://stackoverflow.com/questions/9161512/assignment-operator-inheritance

	The compiler will call the base class operator=
		In the end: final machine code will be equal whether you state the operator= or not
		(running the problem with/without "using" yields the same output, ClapTrap copy assignment is called regardless)

	So,
		- Define it ourselved from scratch
	Subject says constructors must print different messages, not the assignment operator
	As per above, one must still give a definition, otherwise the compiler will infuse its own

	BEFORE:
		i had a bool gatekeeping to track gatekeeping mode
		int he spiriti of the exercise, i removed it in order to directly use the ClapTrap assignment operator


	Inheritance of constructors is only available from c++11 (-std=c++11),
	not here :)
		"error: inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’ [-Werror]"
		but one can still "using" the operator=
	Copy constructor is... a constructor!!! not inherited with "using" either

*/

/*
	OVERRIDE
		override keyword is only available for c++11 and on :)
		error: override controls (override/final) only available with ‘-std=c++11’ or ‘-std=gnu++11’ [-Werror]



*/

#endif
