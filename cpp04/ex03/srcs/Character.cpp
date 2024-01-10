/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 17:47:24 by codespace        ###   ########.fr       */
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
	if (!m)
	{
		std::cout << "Character -" << getName() << "- failed to equip: NULL AMateria" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		if (!sources[i])
		{
			sources[i] = m;
			std::cout << "Character -" << getName() << "- succeeded to equip -" \
			<< m->getType() << "- in slot: " << i << std::endl;
			return ;
		}
	}
	std::cout << "Character -" << getName() << "- failed to equip: unavaiable slots" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= CHARACTER_SLOTS || sources[idx] == NULL)
	{
		std::cout << "Character -" << getName() << "- failed to unequip: bad index/empty slot" << std::endl;
		return ;
	}
	sources[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= CHARACTER_SLOTS || !sources[idx])
	{
		std::cout << "Character -" << getName() << "- failed to use: bad index/empty slot" << std::endl;
		return ;
	}
	sources[idx]->use(target);
}
