/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:14:13 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 15:14:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <new>

Zombie *newZombie (std::string name)
{
    Zombie      *z;

    z = new (std::nothrow) Zombie;
    if (!z)
        return (NULL);
    z->set_namezzz(name);
    return (z);
}
