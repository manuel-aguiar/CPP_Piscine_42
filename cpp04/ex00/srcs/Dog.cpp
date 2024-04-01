/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	if (this == &copy)
		return ;
	*this = copy;
}

Dog& Dog::operator= (const Dog& assign)
{
	if (this == &assign)
		return (*this);
	Animal::operator=(assign);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\nWoof Woof Woof\n" << std::endl;
}
