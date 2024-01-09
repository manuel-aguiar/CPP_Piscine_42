/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:58:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP

#define DiamondTrap_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


#define DIAM_START_NAME "Unnamed"
#define DIAM_START_HP 100
#define DIAM_START_EP 50
#define DIAM_START_ATTACK 20

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		//DiamondTrap(const std::string& name);
		~DiamondTrap();
		//DiamondTrap& operator= (const DiamondTrap& assign);
		//DiamondTrap(const DiamondTrap& copy);

		using	ScavTrap::attack;

		void	whoAmI();

	private:
		std::string	name;
};




#endif
