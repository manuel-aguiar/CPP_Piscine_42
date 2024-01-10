/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 14:20:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	if (this == &copy)
		return ;
	type = copy.type;
}

Animal& Animal::operator= (const Animal& assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this) ;
}

void	Animal::makeSound(void) const
{
	std::cout << "\nI am an Animal, what sound do i make?\n" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (type);
}
