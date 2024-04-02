/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 13:35:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap one("one");
	ScavTrap two("two");

	two = one;

/*
	ScavTrap cenas(potato);

	potato.takeDamage(20);
	potato.attack("cenas");
	potato.my_stats();
	cenas = potato;
	cenas.my_stats();


	std::cout << "\nassign scav into clap:" << std::endl;
	ClapTrap *poli = new ScavTrap;
	*poli = potato;
	poli->my_stats();

	std::cout << "\nassign scav into clap:" << std::endl;
	std::cout << "instantiate scav:" << std::endl;
	ScavTrap scav("tretas");
	std::cout << "instantiate clap:" << std::endl;
	ClapTrap clap("cenas");
	std::cout << "assignment:" << std::endl;
	clap = scav;

	std::cout << sizeof(ClapTrap) << " " << sizeof(ScavTrap) << std::endl;

	delete poli;
*/
    return (0);
}
