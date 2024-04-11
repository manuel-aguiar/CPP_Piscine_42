/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:45:17 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 10:49:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Serializer Constructor called" << std::endl;
	#endif
}

Serializer::~Serializer()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Serializer Destructor called" << std::endl;
	#endif
}

Serializer::Serializer(const Serializer& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Serializer Copy Constructor called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

Serializer& Serializer::operator=(const Serializer& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Serializer Copy Assignment called" << std::endl;
	#endif
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{

}

Data* Serializer::deserialize(uintptr_t raw)
{

}
