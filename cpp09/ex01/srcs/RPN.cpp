/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:42:37 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 11:25:46 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RPN Constructor called" << std::endl;
	#endif
}

RPN::RPN(const std::string& str) : _arg(str)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RPN Constructor called" << std::endl;
	#endif
}

RPN::~RPN()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RPN Destructor called" << std::endl;
	#endif
}

RPN::RPN(const RPN& copy) :
    _arg(copy._arg),
    _operands(copy._operands)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RPN Copy Constructor called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

RPN& RPN::operator=(const RPN& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RPN Copy Assignment called" << std::endl;
	#endif
	_arg = assign._arg;
    _operands = assign._operands;
	return (*this);
}