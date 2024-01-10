/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:02:08 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 15:12:29 by codespace        ###   ########.fr       */
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
