/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 17:02:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include "ICharacter.hpp"

# define CHARACTER_SLOTS 4

class Character : public ICharacter
{
	public:
		Character(const std::string& new_name);

		~Character();

		Character(const Character& copy);
		Character& operator= (const Character& assign);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string 	name;
		unsigned int	used_slots;
		AMateria* 		sources[CHARACTER_SLOTS];
};


#endif
