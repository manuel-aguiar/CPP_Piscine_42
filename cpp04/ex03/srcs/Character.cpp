/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:56 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 11:20:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(const std::string& new_name) : name(new_name)
{
	std::cout << "Character constructor called" << std::endl;
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
		slots[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

Character::Character(const Character& copy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	if (this == &copy)
		return ;
	for(unsigned int i = 0; i < CHARACTER_SLOTS; i++)
		slots[i] = 0;
	*this = copy;
}

Character&	Character::operator= (const  Character& assign)
{
	std::cout << "Character Copy Assignment called" << std::endl;

	if (this == &assign)
		return (*this);
	for(unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		if (slots[i])
		{
			delete slots[i];
			slots[i] = 0;
		}
		if (assign.slots[i])
			slots[i] = assign.slots[i]->clone();
	}
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
		std::cout << "Character -" << name << "- failed to equip: NULL AMateria" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		if (!slots[i])
		{
			slots[i] = m;
			std::cout << "Character -" << name << "- succeeded to equip -" \
			<< m->getType() << "- in slot: " << i << std::endl;
			return ;
		}
	}
	std::cout << "Character -" << name << "- failed to equip: unavaiable slots" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= CHARACTER_SLOTS || slots[idx] == NULL)
	{
		std::cout << "Character -" << name << "- failed to unequip: bad index/empty slot" << std::endl;
		return ;
	}
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= CHARACTER_SLOTS || !slots[idx])
	{
		std::cout << "Character -" << name << "- failed to use: bad index/empty slot" << std::endl;
		return ;
	}
	slots[idx]->use(target);
}

void	Character::print_stats(void) const
{
	std::cout << "\nCharacter Stats: " << name << std::endl;
	std::cout << "Materias: " << std::endl;
	for (unsigned int i = 0; i < CHARACTER_SLOTS; i++)
	{
		std::cout << "   Slot " << i << ": ";
		if (slots[i])
			std::cout << slots[i]->getType();
		else
			std::cout << "empty";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	Character::setName(const std::string& new_name)
{
	name = new_name;
}

const AMateria* Character::getSlot(int idx) const
{
	if (idx < 0 || idx >= CHARACTER_SLOTS || slots[idx] == NULL)
	{
		std::cout << "Character -" << name << "- slot is empty/out of bounds" << std::endl;
		return (NULL);
	}
	return (slots[idx]);
}
