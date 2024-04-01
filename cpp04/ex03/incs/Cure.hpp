/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:28 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 12:08:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"


class Cure : public AMateria
{
	public:
		Cure();

		~Cure();

		Cure(const Cure& copy);
		Cure& operator= (const Cure& assign);

		//declaring Amateria's virtual funcs
		void	use(ICharacter& target);
		Cure*	clone() const;
};

#endif
