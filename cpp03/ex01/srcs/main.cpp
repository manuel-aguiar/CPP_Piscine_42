/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 17:19:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap* potato = new ScavTrap();



	potato->my_stats();

	potato->attack("tretas");

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

    return 0;
}
