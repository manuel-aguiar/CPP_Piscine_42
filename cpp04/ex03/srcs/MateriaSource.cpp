/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:03 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 18:06:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Constructor called" << std::endl;
	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
		sources[i] = NULL;
	used_slots = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;

	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (sources[i])
			delete sources[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "MateriaSource Copy Destructor called" << std::endl;
	if (this == &copy)
		return ;
	for(unsigned int i = 0; i < MATERIA_SLOTS; i++)
		sources[i] = copy.sources[i];
	used_slots = copy.used_slots;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& assign)
{
	std::cout << "MateriaSource Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	for(unsigned int i = 0; i < MATERIA_SLOTS; i++)
		sources[i] = assign.sources[i];
	used_slots = assign.used_slots;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "MateriaSource failed to learn, empty AMateria" << std::endl;
		return ;
	}
	if (used_slots == MATERIA_SLOTS)
	{
		std::cout << "MateriaSource failed to learn, no slots" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (!sources[i])
		{
			sources[i] = m;
			used_slots++;
			std::cout << "MateriaSource successufully learned: " << m->getType() \
			<< ": saved on slot " << i << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (sources[i])
		{
			if (sources[i]->getType() == type)
			{
				std::cout << "MateriaSource successufully created: " << type << " : found on slot " << i << std::endl;
				return (sources[i]->clone());
			}
		}
	}
	std::cout << "MateriaSource failed to create: " << type << " : not found on any slot" << std::endl;
	return (NULL);
}
