/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 18:13:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(const std::string& new_name) : name(new_name)
{
	std::cout << "Character constructor called" << std::endl;
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
		sources[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		if (sources[i])
			delete sources[i];
	}
}

Character::Character(const Character& copy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	if (this == &copy)
		return ;
	for(unsigned int i = 0; i < CHARACTER_SLOTS; i++)
		sources[i] = copy.sources[i];
	name = copy.name;
}

Character&	Character::operator= (const  Character& assign)
{
	std::cout << "Character Copy Assignment called" << std::endl;

	if (this == &assign)
		return (*this);
	for(unsigned int i = 0; i < CHARACTER_SLOTS; i++)
		sources[i] = assign.sources[i];
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
