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
	my_brain = new (std::nothrow) Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete my_brain;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	if (this == &copy)
		return ;
	my_brain = new (std::nothrow) Brain();
	*this = copy;
}

Dog& Dog::operator= (const Dog& assign)
{
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	type = assign.type;
	*my_brain = *(assign.my_brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\nWoof Woof Woof\n" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (my_brain);
}
