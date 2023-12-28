/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:02:13 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:02:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
    Zombie *z = newZombie("yoyoyo");

	randomChump("brah");
    z->announce();
    Zombie stacker = *z;
	*z = stacker;
	z->set_namezzz("another is now: POTATO");
	z->announce();
    randomChump("cenas");
    stacker.announce();
    stacker.set_namezzz("changing name");
    stacker.announce();


    delete z;

    return (0);
}
