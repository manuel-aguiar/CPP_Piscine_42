/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice Constructor called" << std::endl;
	type = "Ice";
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	std::cout << "Ice Copy Destructor called" << std::endl;
	if (this == &copy)
		return ;
}

Ice& Ice::operator= (const Ice& assign)
{
	std::cout << "Ice Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	return (*this);
}
