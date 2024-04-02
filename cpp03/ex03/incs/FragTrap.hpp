/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:12 by codespace         #+#    #+#             */
/*   Updated: 2024/04/02 12:54:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


#define FRAG_START_NAME "Unnamed"
#define FRAG_START_HP 100
#define FRAG_START_EP 100
#define FRAG_START_ATTACK 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& start_name);
		~FragTrap();
		FragTrap(const FragTrap& copy);

		//using ClapTrap::operator=;

		FragTrap& operator= (const FragTrap& assign);

		void	highFivesGuys(void);
};

/*

	Virtual inheritance from ClapTrap, in case there are subclasses of FragTrap and
	those inherit from Base class as well, only one instance of Base Class is instantiated

	Both superclasses of DiamondTrap must inherit virtually, otherwise the compiler
	will complaint about ambiguity

*/


#endif
