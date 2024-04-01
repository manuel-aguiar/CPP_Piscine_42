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
# include "Brain.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	type = "Cat";
	my_brain = new (std::nothrow) Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete my_brain;
}

/*
	heap allocation of a new empty brain

	calls assignment operator
		which calls brain assignment operator
*/

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat Copy Destructor called" << std::endl;
	if (this == &copy)
		return ;
	my_brain = new (std::nothrow) Brain();
	*this = copy;
}

Cat& Cat::operator= (const Cat& assign)
{
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	type = assign.type;
	*my_brain = *(assign.my_brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "\nMiauuuuu\n" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (my_brain);
}
