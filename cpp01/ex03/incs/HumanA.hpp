/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:50 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 11:59:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{

    public:

		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
		HumanA(const HumanA& copy);
		HumanA& operator= (const HumanA& assign);

		void    attack();

    private:

		std::string     name;
		Weapon&	  weapon;
		HumanA();

};






#endif
