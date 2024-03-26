/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:54 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 10:56:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : raw_bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int i ) : raw_bits(i << frac_bits)
{
    std::cout << "Int constructor called" << std::endl;
	if (i > FIXED_INT_MAX || i < FIXED_INT_MIN)
		std::cout << "warning: int is outside fixed point accuracy range" << std::endl;
}

Fixed::Fixed( const float f ) : raw_bits(roundf(f * (1 << frac_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : raw_bits(copy.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
    if (this == &copy)
    {
		std::cout << "Copy constructor: this == copy" << std::endl;
		return ;
    }
	*this = copy;
}

Fixed& Fixed::operator= (const Fixed& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
		std::cout << "Copy assignment: this == copy" << std::endl;
		return (*this);
    }
    raw_bits = assign.getRawBits();
    return (*this);
}

float   Fixed::toFloat( void ) const
{
    return ((float)raw_bits / (1 << frac_bits));
}

int     Fixed::toInt( void ) const
{
    return (raw_bits >> frac_bits);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (raw_bits);
}

void     Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called" << std::endl;
    raw_bits = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num)
{
	out << num.toFloat();
	return (out);
}
