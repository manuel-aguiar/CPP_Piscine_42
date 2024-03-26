/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:59:15 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 10:09:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : raw_bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : raw_bits(copy.raw_bits)
{
    std::cout << "Copy constructor called" << std::endl;
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
