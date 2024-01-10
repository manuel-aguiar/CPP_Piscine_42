/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:03 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 17:01:50 by codespace        ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria* )
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	(void)type;
	return (NULL);
}
