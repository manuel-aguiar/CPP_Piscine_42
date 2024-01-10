/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:23:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	if (this == &copy)
		return ;
	type = copy.type;
}

AMateria& AMateria::operator= (const AMateria& assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this) ;
}

void	AMateria::makeSound(void) const
{
	std::cout << "\nI am an AMateria, what sound do i make?\n" << std::endl;
}

const std::string& AMateria::getType(void) const
{
	return (type);
}
