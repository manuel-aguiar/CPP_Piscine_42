/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	if (this == &copy)
		return ;
	type = copy.type;
}

Cat& Cat::operator= (const Cat& assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "\nMiauuuuu\n" << std::endl;
}
