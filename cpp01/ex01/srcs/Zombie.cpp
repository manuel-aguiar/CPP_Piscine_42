/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:01:33 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:01:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "nameless: constructedzzzzz" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": deadzzzzzzzzz" << std::endl;
}

Zombie::Zombie(const Zombie& copy)
{
	std::cout << copy.name << ": copiedzzzzz" << std::endl;
    if (this == &copy)
	 return ;
    this->name = copy.name;
}

Zombie  &Zombie::operator=(const Zombie& assign)
{
	std::cout << assign.name << ": copy-assignedzzzzz" << std::endl;
    if (this == &assign)
	 return (*this);
    this->name = assign.name;
    return (*this);
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_namezzz(const std::string &my_name)
{
    this->name = my_name;
}

const std::string& Zombie::get_namezzz(void) const
{
	return (this->name);
}
