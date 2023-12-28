/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:54:54 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:33:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors

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

//destructors

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

// copy constructor

Fixed::Fixed(const Fixed& copy) : raw_bits(copy.raw_bits)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this == &copy)
    {
        std::cout << "Copy constructor: this == copy" << std::endl;
        return ;
    }
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


