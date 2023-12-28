/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:09:29 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 13:34:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(const Fixed& x, const Fixed& y);
		~Point();
		Point(const Point& copy);
		Point& operator=(const Point& assign);

		Fixed	get_x( void ) const;
		Fixed	get_y( void ) const;

	private:
		Point(void);
		Fixed	x;
		Fixed	y;
};

bool	bsp(const Point& target, const Point& a, const Point& b, const Point& c);

#endif
