/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:06:07 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 10:50:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MATERIA_SLOTS 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator= (const MateriaSource& assign);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria* 		sources[MATERIA_SLOTS];
};

#endif
