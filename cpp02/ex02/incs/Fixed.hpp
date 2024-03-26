/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:05 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 11:40:28 by codespace        ###   ########.fr       */
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

		int				getRawBits( void ) const;
		void			setRawBits( int const raw);
		float			toFloat( void ) const;
		int				toInt( void ) const;

		// comparison operator overloads
		bool	operator> (const Fixed& other) const;
		bool	operator< (const Fixed& other) const;
		bool	operator>= (const Fixed& other) const;
		bool	operator<= (const Fixed& other) const;
		bool	operator== (const Fixed& other) const;
		bool	operator!= (const Fixed& other) const;

		// arithmatic operator overloads

		Fixed	operator+ (const Fixed& other) const;
		Fixed	operator- (const Fixed& other) const;
		Fixed	operator* (const Fixed& other) const;
		Fixed	operator/ (const Fixed& other) const;


		// increment operator overloads

		Fixed&	operator++(void);
		Fixed	operator++(int);

		Fixed&	operator--(void);
		Fixed	operator--(int);

		// public static member functions

		static	Fixed&			min(Fixed& first, Fixed& second);
		static	const Fixed&	min(const Fixed& first, const Fixed& second);
		static	Fixed&			max(Fixed& first, Fixed& second);
		static	const Fixed&	max(const Fixed& first, const Fixed& second);

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
		"<<" as a stream insertion operator is left-to-right :)
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

	Associativity is used to evaluate the order of execution of operators of the same precedence
	a + b + c -> same operator, same precedence
	left to right, so a + b and then the return of that + c;
	a + b * c * d, * has higher precendence than +, * evaluated first.
	* is left to right, so b * c, then res * d, then a + res

*/

/*

	The reason for the two types of static member functions (const/non-const)
	is because:
		if we are chaining the results, we need non-const Fixed instances to carry the math from
		one to the next

*/

#endif
