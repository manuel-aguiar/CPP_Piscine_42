/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 12:53:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP

#define FragTrap_HPP

#include "ClapTrap.hpp"


#define FRAG_START_NAME "Unnamed"
#define FRAG_START_HP 100
#define FRAG_START_EP 100
#define FRAG_START_ATTACK 30

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap& operator= (const FragTrap& assign);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};




#endif
