/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:57:58 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 11:55:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

# include "Fixed.hpp"

class Vector
{
	public:
		Vector(const Fixed& x, const Fixed& y);
		~Vector();
		Vector(const Vector& copy);
		Vector& operator=(const Vector& assign);


		void			set_x(const Fixed& x_coord);
		void			set_y(const Fixed& y_coord);

		const Fixed&	get_x( void ) const;
		const Fixed&	get_y( void ) const;

		static Fixed	cross_product (Vector& first, Vector& second);
		
		Vector	operator- (const Vector& other) const;

	private:
		Vector(void);
		Fixed	x;
		Fixed	y;
};

bool	bsp(const Vector& target, const Vector& a, const Vector& b, const Vector& c);

#endif
