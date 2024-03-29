/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:06:37 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 10:06:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>


/*

Representing fixed point numbers of type <32, 8>, meaning:
	32 total bits
	8 rightmost bits are used for the fraction

	member raw_bits: all the bits represented as if it was an integer
	member fraction_bits: number of rightmost bits used for the fraction part:
		23 bits for the integer part
		8 bits for the floating part (static const initialized imeddiatelly)
		1 bit for sign of the number

*/

# define FRAC_BITS 8

class Fixed
{
    public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed&  operator= (const Fixed& assign);

		int     getRawBits( void ) const;
		void    setRawBits( int const raw);

    private:
		int					raw_bits;
		static const int	frac_bits = FRAC_BITS;
};

#endif
