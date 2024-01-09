/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:14 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 15:02:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define START_HP 10
#define START_EP 10
#define START_ATTACK 0
#define START_NAME "Unnamed"

class ClapTrap
{
    public:
		ClapTrap();
		ClapTrap(const std::string& start_name);
		~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator= (const ClapTrap& assign);

		void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);
		void    my_stats( void );

    private:
		std::string name;
		unsigned int hitpoints;
		unsigned int energypoints;
		unsigned int attackdamage;
};




#endif
