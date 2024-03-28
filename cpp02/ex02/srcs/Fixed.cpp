/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:23 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 11:10:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors

Fixed::Fixed( void ) : raw_bits(0)
{
    std::cout << "Default constructor called, raw_bits: " << raw_bits << std::endl;
}

Fixed::Fixed( const int i ) : raw_bits(i << frac_bits)
{
    std::cout << "Int constructor called, raw_bits: " << raw_bits << std::endl;
	if (i > FIXED_INT_MAX || i < FIXED_INT_MIN)
		std::cout << "warning: int is outside fixed point accuracy range" << std::endl;
}

Fixed::Fixed( const float f ) : raw_bits(roundf(f * (1 << frac_bits)))
{
    std::cout << "Float constructor called, raw_bits: " << raw_bits << std::endl;
}

//destructors

Fixed::~Fixed( void )
{
    std::cout << "Destructor called, raw_bits: " << raw_bits << std::endl;
}

// copy constructor

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

//copy assignment constructor

Fixed& Fixed::operator= (const Fixed& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
		std::cout << "Copy assignment: this == copy" << std::endl;
		return (*this);
    }
    raw_bits = assign.raw_bits;
    return (*this);
}

// generic member functions

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (this->raw_bits);
}

void     Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called" << std::endl;
    this->raw_bits = raw;

}


