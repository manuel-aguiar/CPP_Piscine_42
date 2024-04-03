/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/03 14:48:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("one");

	scav.my_stats();

	ClapTrap clap("cenas");

	ClapTrap *clap_in_scav = &scav;

	*clap_in_scav = clap;

	scav.my_stats();
	scav.attack("tozé");

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
