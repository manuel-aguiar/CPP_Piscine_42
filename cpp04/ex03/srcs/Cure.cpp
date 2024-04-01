/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() : AMateria()
{
	std::cout << "Cure Constructor called" << std::endl;
	type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
	std::cout << "Cure Copy Destructor called" << std::endl;
	if (this == &copy)
		return ;
	*this = copy;
}

Cure& Cure::operator= (const Cure& assign)
{
	std::cout << "Cure Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}
