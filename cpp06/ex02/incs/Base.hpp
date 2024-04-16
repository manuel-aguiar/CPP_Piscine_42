/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:59:14 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 12:02:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP

# define BASE_HPP

# include "Base.hpp"
# include <iostream>

class Base
{
	public:
		virtual ~Base();
};

extern int g_rand_seed;

Base*	generate(void) throw(std::bad_alloc);
void	identify(Base* p);
void	identify(Base& p);

#endif

