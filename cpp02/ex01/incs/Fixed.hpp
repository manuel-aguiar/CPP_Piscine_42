/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:18:13 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 10:57:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

/*

Representing fixed point numbers of type <32, 8>, meaning:
	32 total bits
	8 rightmost bits are used for the fraction

	member raw_bits: all the bits represented as is it was an integer
	member fraction_bits: number of rightmost bits used for the fraction part:
		23 bits for the integer part
		8 bits for the floating part (static const initialized imeddiatelly)
		1 bit for sign of the number

Converting an int to fixed point of fraction 8 means the loss of 8 bits to
represent a full int
Therefore fixed_point FIXED_INT_MAX = INT_MAX >> 8
					  FIXED_INT_MIN = INT_MIN >> 8

*/

# include <iostream>
# include <cmath>
# include <limits.h>

# define FRAC_BITS 8

# define FIXED_INT_MAX (INT_MAX >> FRAC_BITS)
# define FIXED_INT_MIN (INT_MIN >> FRAC_BITS)

class Fixed
{
    public:
		Fixed();
		Fixed( const int i );
		Fixed( const float f );
		~Fixed();
		Fixed( const Fixed& copy );
		Fixed&  operator= ( const Fixed& assign );

		//friend std::ostream& operator<<(std::ostream& out, const Fixed& num);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

    private:
		int					raw_bits;
		static const int	frac_bits = FRAC_BITS;

};

/*
	Placing the overload inside the class requires the use of the friend keywork which is forbidden
	It is the std::ostream class that is being overloaded with a new prototype
		polimorphism guarantees that when overloading with our class's prototype, compilation
		will make use of the overload we created on OSTREAM for our own class

	In reality we are providing a new operator overload to std::ostream to be able to print our class

	friend keyword inside our class would allow std::ostream to access our class via this function
		(forbidden for exercise purposes)


	this is called a "non-member function overload", same as std::string can << to std::cout
		there is an overload of std::cout that takes a std::string as input and allows it to print
		to cout

	std::cout has multiple overloads for the various classes
		the correct overload is decided at compile time taking into account the input parameters
		that are given to the operator
		- compile-time polymorphism

*/

std::ostream& operator<<(std::ostream& out, const Fixed& num);

/*
	returning a reference to the output stream itself is what allows
	chaining of thee operator<< !!!!!!!!
	the next one will be able to still be called because they have
	a reference to cout left byt he previous function call
*/

/*

	cortesy of chatgpt:
	Left-to-right associativity: +, -, *, /, %, =, +=, -=, *=, /=, %=, etc.
	Right-to-left associativity: ++, --, <<, >>, =, +=, -=  (when used as unary operators)

	WAIT (not chatgpt):
		"<<" has stream insertion operator is left-to-right :)
		chatgpt is referring to bitshifts

	certain operators work left to right and others as right to left.
	Example:
		f = g = h
		is equal to:
		g = h
		f = g

		So, h gets effectively passed to f, "=" operator has right-left associativity

	++ and --

	Since these operators have right-to-left associativity,
	x++, returns original x and increases x
	++x, increases x and returns the new increased x


	Overloading operators does not change their associacitivity, only how the operator itself behaves


*/

#endif
