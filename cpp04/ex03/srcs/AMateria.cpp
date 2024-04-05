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
	std::cout << "AMateria Copy Destructor called" << std::endl;
	if (this == &copy)
		return ;
	*this = copy;
}

AMateria& AMateria::operator= (const AMateria& assign)
{
	std::cout << "AMateria Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this) ;
}

const std::string& AMateria::getType(void) const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "* something..... at " << "target.getName()" << " *" << std::endl;
}
