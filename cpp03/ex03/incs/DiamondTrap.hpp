/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:28:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP

#define DiamondTrap_HPP

#include "ClapTrap.hpp"


#define DIAM_START_NAME "Unnamed"
#define DIAM_START_HP 100
#define DIAM_START_EP 50
#define DIAM_START_ATTACK 20

class DiamondTrap : public ClapTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator= (const DiamondTrap& assign);
		void	attack(const std::string& target);
		void    guardGate();
	private:
		bool    gatekeeping;
};




#endif
