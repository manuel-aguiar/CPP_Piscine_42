/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:12:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
    this->type = type;
}


Weapon::Weapon()
{

}

Weapon::~Weapon()
{

}

Weapon::Weapon(const Weapon& copy) : type(copy.type)
{
    if (this == &copy)
		return ;
}

Weapon& Weapon::operator=(const Weapon& assign)
{
    if (this == &assign)
	 return (*this);
    this->type = assign.type;
    return (*this);
}

const std::string& Weapon::getType() const
{
    return (this->type);
}

void    Weapon::setType(const std::string& type)
{
    this->type = type;
}
