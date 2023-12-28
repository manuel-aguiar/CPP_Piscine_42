/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:13:06 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 13:34:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const Fixed& x, const Fixed& y) : x(x) , y(y)
{
	std::cout << "Point constructor called" << std::endl;
}

//destructors

Point::~Point( void )
{
    std::cout << "Destructor called" << std::endl;
}

// copy constructor

Point::Point(const Point& copy) : x(copy.x) , y(copy.y)
{
    std::cout << "Point Copy constructor called" << std::endl;
    if (this == &copy)
    {
        std::cout << "Point Copy constructor: this == copy" << std::endl;
        return ;
    }
}

//copy assignment constructor

Point& Point::operator= (const Point& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
        std::cout << "Copy assignment: this == copy" << std::endl;
        return (*this);
    }
    x = assign.x;
	y = assign.y;
    return (*this);
}

Fixed	Point::get_x( void ) const
{
	return (x);
}

Fixed	Point::get_y( void ) const
{
	return (y);
}
