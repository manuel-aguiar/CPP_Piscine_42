/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:23:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FlagTrap_HPP

#define FlagTrap_HPP

#include "ClapTrap.hpp"


#define FLAG_START_NAME "Unnamed"
#define FLAG_START_HP 100
#define FLAG_START_EP 100
#define FLAG_START_ATTACK 30

class FlagTrap : public ClapTrap
{
	public:
		FlagTrap();
		FlagTrap(const std::string& name);
		~FlagTrap();
		FlagTrap(const FlagTrap& copy);
		FlagTrap& operator= (const FlagTrap& assign);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};




#endif
