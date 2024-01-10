/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 09:53:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


#define SCAV_START_NAME "Unnamed"
#define SCAV_START_HP 100
#define SCAV_START_EP 50
#define SCAV_START_ATTACK 20

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& start_name);
		~ScavTrap();
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator= (const ScavTrap& assign);

		void	attack(const std::string& target);
		void    guardGate();
	protected:
		bool    gatekeeping;
};




#endif
