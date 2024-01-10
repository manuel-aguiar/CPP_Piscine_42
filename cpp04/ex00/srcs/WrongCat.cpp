/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	if (this == &copy)
		return ;
	type = copy.type;
}

WrongCat& WrongCat::operator= (const WrongCat& assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "\nMiauuuuu\n" << std::endl;
}
