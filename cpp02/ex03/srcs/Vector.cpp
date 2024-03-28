/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:57:12 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 12:12:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector(const Fixed& x, const Fixed& y) : x(x) , y(y)
{
	std::cout << "Vector constructor called" << std::endl;
}

//destructors

Vector::~Vector( void )
{
    std::cout << "Vector Destructor called" << std::endl;
}

// copy constructor

Vector::Vector(const Vector& copy) : x(copy.x) , y(copy.y)
{
    std::cout << "Vector Copy constructor called" << std::endl;
    if (this == &copy)
    {
		std::cout << "Vector Copy constructor: this == copy" << std::endl;
		return ;
    }
}

//copy assignment constructor

Vector& Vector::operator= (const Vector& assign)
{
    std::cout << "Vector Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
		std::cout << "Vector Copy assignment: this == copy" << std::endl;
		return (*this);
    }
    x = assign.x;
	y = assign.y;
    return (*this);
}

// getters setters

void	Vector::set_x( const Fixed& x_coord )
{
	x = x_coord;
}

void	Vector::set_y(  const Fixed& y_coord )
{
	y = y_coord;
}

const Fixed&	Vector::get_x( void ) const
{
	return (x);
}

const Fixed&	Vector::get_y( void ) const
{
	return (y);
}

Vector	Vector::operator- (const Vector& other) const
{
	Vector res (x - other.get_x(),
				y - other.get_y());
	return (res);
}

Fixed	Vector::cross_product(Vector& first, Vector& second)
{
	return (first.x * second.y - first.y * second.x);
}
