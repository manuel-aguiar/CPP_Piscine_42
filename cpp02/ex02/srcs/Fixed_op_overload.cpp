/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_op_overload.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:18 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 11:42:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator> (const Fixed& other) const
{
	return (raw_bits > other.raw_bits);
}

bool	Fixed::operator< (const Fixed& other) const
{
	return (raw_bits < other.raw_bits);
}

bool	Fixed::operator>= (const Fixed& other) const
{
	return (raw_bits >= other.raw_bits);
}

bool	Fixed::operator<= (const Fixed& other) const
{
	return (raw_bits <= other.raw_bits);
}

bool	Fixed::operator== (const Fixed& other) const
{
	return (raw_bits == other.raw_bits);
}

bool	Fixed::operator!= (const Fixed& other) const
{
	return (raw_bits != other.raw_bits);
}

// member operator overloads (arithmatic operations)

Fixed	Fixed::operator+ (const Fixed& other) const
{
	Fixed res (this->toFloat() + other.toFloat());
	return (res);
}

Fixed	Fixed::operator- (const Fixed& other) const
{
	Fixed res (this->toFloat() - other.toFloat());
	return (res);
}

Fixed	Fixed::operator* (const Fixed& other) const
{
	Fixed res (this->toFloat() * other.toFloat());
	return (res);
}

Fixed	Fixed::operator/ (const Fixed& other) const
{
	Fixed res (0);
	if (other.raw_bits == 0)
		return (res);
	res = this->toFloat() / other.toFloat();
	return (res);
}

// increment operator overloads (increment/decrement)

/*
	Below is the pre-increment overload,
	increment the original and returns a reference to it
	this reference is not const, the next user can change the Fixed point number
*/

Fixed&	Fixed::operator++(void)
{
	++raw_bits;
	return (*this);
}

/*
	Below is the post-increment overload,
	save a copy of the original, increment the original,
	return the copy

	internally, it is calling the pre-increment overload above
	at the line ++(*this)

	int is a DUMMY, one does not pass anything
		part of the language and the compiler parsing, meaning
		that we ALWAYS put "int" as a parameter to overload the
		post increment operator
		(if you put "char", it wont compile :)
		"error: postfix ‘Fixed Fixed::operator++(char)’ must have ‘int’ as its argument")
		the -wall -werror -wextra flags do not complain that int is not utilized
		it is already taken into account in the parser of the compiler
*/

Fixed	Fixed::operator++(int)
{
	Fixed copy (*this);

	++(*this);
	return (copy);
}

Fixed&	Fixed::operator--(void)
{
	--raw_bits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed copy (*this);

	--(*this);
	return (copy);
}
