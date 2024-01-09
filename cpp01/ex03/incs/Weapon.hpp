/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:54 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:11:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <string>

class Weapon
{

    public:
		Weapon (const std::string& type);
		Weapon (const Weapon& copy);
		~Weapon ();
		Weapon& operator= (const Weapon& assign);

		const std::string&	getType() const;
		void				setType(const std::string& type);

    private:
		std::string     type;
		Weapon();


};

















#endif
