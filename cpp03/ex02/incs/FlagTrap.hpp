/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 15:02:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


#define FRAG_START_NAME "Unnamed"
#define FRAG_START_HP 100
#define FRAG_START_EP 100
#define FRAG_START_ATTACK 30

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& start_name);
		~FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap& operator= (const FragTrap& assign);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};




#endif
