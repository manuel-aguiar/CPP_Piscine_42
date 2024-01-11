/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:03 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 10:49:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Constructor called" << std::endl;
	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
		sources[i] = NULL;
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
}

MateriaSource& MateriaSource::operator= (const MateriaSource& assign)
{
	std::cout << "MateriaSource Copy Assignment called" << std::endl;
	if (this == &assign)
		return (*this);
	for(unsigned int i = 0; i < MATERIA_SLOTS; i++)
		sources[i] = assign.sources[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "MateriaSource failed to learn, empty AMateria" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < MATERIA_SLOTS; i++)
	{
		if (!sources[i])
		{
			sources[i] = m;
			std::cout << "MateriaSource successufully learned: " << m->getType() \
			<< ": saved on slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource failed to learn, no slots" << std::endl;
	return ;
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
