/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:52 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:00:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{

    public:
	 HumanB(const std::string& name);
	 ~HumanB();
	 HumanB(const HumanB& copy);
	 HumanB& operator= (const HumanB& assign);

	 void    attack();
	 void    setWeapon(Weapon& weapon);

    private:
	 std::string     name;
	 Weapon*	  weapon;
	 HumanB();
};






#endif
