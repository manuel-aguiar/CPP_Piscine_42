/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 09:55:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap* potato = new FragTrap();



	potato->my_stats();

	// this function will call ClapTrap attack
	potato->attack("tretas");

	ClapTrap* ya_man = new ScavTrap("cenas");
	// this function will call ScavTrap attack
	ya_man->attack("tretas");

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

	delete potato;
	delete ya_man;

    return 0;
}
