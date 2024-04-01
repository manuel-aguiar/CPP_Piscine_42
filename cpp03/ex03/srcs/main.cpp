/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 11:33:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap cenas("tretas");

	cenas.whoAmI();

	cenas.my_stats();

	cenas.attack("batata");

	DiamondTrap blabla(cenas);

	cenas = blabla;

	cenas.my_stats();

	cenas.guardGate();
	cenas.highFivesGuys();

	/*
    potato.attack("antonio");
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();
    potato.takeDamage(3000);
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();

    ScavTrap cenas (potato);
    cenas.my_stats();
    cenas = potato;
    cenas.my_stats();
	*/

    return (0);
}
