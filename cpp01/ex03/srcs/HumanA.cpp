/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:39 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 11:57:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon& weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{

}

HumanA::HumanA(const HumanA &copy) : name(copy.name), weapon(copy.weapon)
{
    if (this == &copy)
		return ;
}

HumanA& HumanA::operator=(const HumanA &assign)
{
    if (this == &assign)
		return (*this);
    this->name = assign.name;
    this->weapon = assign.weapon;
    return (*this);
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}
