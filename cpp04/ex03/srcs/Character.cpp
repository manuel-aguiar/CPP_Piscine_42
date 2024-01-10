/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 17:07:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(const std::string& new_name) : name(new_name)
{
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& copy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	if (this == &copy)
		return ;
	name = copy.name;
}

Character&	Character::operator= (const  Character& assign)
{
	std::cout << "Character Copy Assignment called" << std::endl;

	if (this == &assign)
		return (*this);
	name = assign.name;
	return (*this);
}

const std::string&	Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{


}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
