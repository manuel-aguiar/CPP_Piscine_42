/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:28:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	if (this == &copy)
		return ;
	type = copy.type;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this) ;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\nI am an WrongAnimal, what sound do i make?\n" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (type);
}
