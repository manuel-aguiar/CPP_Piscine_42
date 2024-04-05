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
	type = "ice";
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
	*this = copy;
}

Ice& Ice::operator= (const Ice& assign)
{
	std::cout << "Ice Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	AMateria::operator=(assign);
	return (*this);
}

Ice*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
