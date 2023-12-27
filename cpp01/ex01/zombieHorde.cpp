/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:51:40 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 15:55:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <new>

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;
    int     i;

    horde = new (std::nothrow) Zombie[N];
    if (!horde)
        return (NULL);

    for (i = 0; i < N; i++)
        horde[i].set_namezzz(name);

    return (horde);
}
