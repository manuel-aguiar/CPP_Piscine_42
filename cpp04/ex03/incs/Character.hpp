/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 11:19:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define CHARACTER_SLOTS 4

class Character : public ICharacter
{
	public:
		Character(const std::string& new_name);

		~Character();

		Character(const Character& copy);
		Character& operator= (const Character& assign);

		// declaring Icharacter's pure virtual functions
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void				setName(const std::string& new_name);
		void				print_stats(void) const;
		const AMateria* 	getSlot(int idx)	const;
	private:
		std::string 	name;
		AMateria* 		slots[CHARACTER_SLOTS];
};


#endif
