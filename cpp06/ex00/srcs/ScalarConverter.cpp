/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 13:05:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Constructor called" << std::endl;
	#endif
}

ScalarConverter::~ScalarConverter()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Destructor called" << std::endl;
	#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Copy Assignment called" << std::endl;
	#endif
	(void)assign;
	return (*this);
}
