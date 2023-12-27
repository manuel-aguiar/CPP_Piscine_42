/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:18:31 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 15:18:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
    Zombie *z = newZombie("yoyoyo");
    randomChump("brah");
    z->announce();
    Zombie stacker = *z;
    randomChump("cenas");
    stacker.announce();
    stacker.set_namezzz("changing name");
    stacker.announce();
    delete z;

    return (0);
}
