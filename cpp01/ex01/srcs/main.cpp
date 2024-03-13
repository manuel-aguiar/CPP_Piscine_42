/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:01:38 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 11:54:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
    int total = 5;
    Zombie *horde;

    horde = zombieHorde(total, "brah");
    if (!horde)
		return (1);
    for (int i = 0; i < total; i++)
		horde[i].announce();

    delete[] horde;
    return (0);
}
