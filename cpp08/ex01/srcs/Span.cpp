/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:57:42 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 10:52:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//private
Span::Span()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Span Default Constructor Called" << std::endl;
	#endif
}

Span::Span(const size_t capacity) :
	_total_capacity(capacity),
	_used_capacity(0),
	_doubled_entry(false)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Span Parameter Constructor Called" << std::endl;
	#endif
	if (_total_capacity <= 1)
		throw std::runtime_error("Span Class capacity must be greater than 1");
}

Span::~Span()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Span Default Destructor Called" << std::endl;
	#endif
}

Span::Span(const Span& copy) :
	_total_capacity(copy._total_capacity),
	_used_capacity(copy._used_capacity),
	_doubled_entry(copy._doubled_entry),
	_numbers(copy._numbers)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Span Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
}

Span&	Span::operator=(const Span& assign)
{
	if (this == &assign)
		return (*this);
	_total_capacity =assign._total_capacity;
	_used_capacity =assign._used_capacity;
	_numbers = assign._numbers;
	_doubled_entry = assign._doubled_entry;
	return (*this);
}
