/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 12:53:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	credit to anshovah:
		"const static unsigned int	scav_starting_energy = SCAV_START_EP"

*/

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

		//using ClapTrap::operator=;

		ScavTrap& operator= (const ScavTrap& assign);

		virtual void    my_stats( void ) const;

		void	attack(const std::string& target);
		void    guardGate();

	protected:
		bool	gatekeeping;
		const static unsigned int	scav_starting_energy = SCAV_START_EP;
};




#endif
