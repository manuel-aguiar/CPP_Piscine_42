/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:49:33 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 12:23:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : a_string("tretas"), a_number(42)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Data Constructor called" << std::endl;
	#endif
}

Data::~Data()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Data Destructor called" << std::endl;
	#endif
}

Data::Data(const Data& copy) : a_string(copy.a_string), a_number(copy.a_number)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Data Copy Constructor called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

Data& Data::operator=(const Data& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Data Copy Assignment called" << std::endl;
	#endif
	a_string = assign.a_string;
	a_number = assign.a_number;
	return (*this);
}
