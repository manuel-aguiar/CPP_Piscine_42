/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:15:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap potato("juau");
	ScavTrap cenas(potato);

	potato.takeDamage(20);
	potato.attack("cenas");
	cenas = potato;
	cenas.my_stats();
	cenas.guardGate();

	ClapTrap *ptr;

	ClapTrap hello("hey");

	hello.attack("cenas");

	ptr = new (std::nothrow) ScavTrap("cenas");
	if (!ptr)
		return (1);
	ptr->attack("cenas");
	/*
		runtime polymorphism, since attack is virtual at ClapTrap,
		at runtime the program will call ScavTrap's "attack".
		If attack is not virtual at ClapTrap, it will cal ClapTrap attack
	*/
	delete ptr;

    return (0);
}
