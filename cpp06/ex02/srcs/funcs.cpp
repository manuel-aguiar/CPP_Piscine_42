/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:05:45 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 09:15:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base*	generate(void)
{
	int 	res;
	Base*	ptr;

	std::srand(std::time(0)); // total waste
	res = std::rand() % 3;
	switch(res)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (0);
	}
	return (0);
}

void	identify(Base* p)
{

}

void	identify(Base& p)
{

}
