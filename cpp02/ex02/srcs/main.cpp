/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:28 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 11:27:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int main( void )
{

	/*
		A word on Scope:
			Fixed(2.5f) is constructed, then Fixed(Fixed(c) * Fixed(2.5f)) is constructed
			Immediatelly after the operation is printed, since the return value
			is not saved in any variable, the compiler calls the destructors for
			Fixed(2.5f) and Fixed(Fixed(c) * Fixed(2.5f))

		The compiler itself infuses the constructors for the intermediate classes
	*/
	Fixed c (2);

	std::cout << (c > 0) << std::endl;		// compiler calls Fixed(0) and promotes it to class Fixed
	std::cout << (c * 2.5f) << std::endl;	// compiler calls Fixed(2.5f) and promotes it to class Fixed
	std::cout << "math done" << std::endl;

	/*

		Constructors, precedence and associativity:
		Fixed a : default constructor that sets the raw_bits to zero
		Next line:
			to construct b, one needs (fixed (5.05f) and fixed (2))
			The compiler first calls fixed(2) and only after fixed(5.05f)
			which is strange given that multiplication is left-to-right associative...? :0

		Finally, one b is instantiated, the compiler infuses the destructor code for the
		intermediate instances (2 and 5.05f). So, again, scope is not only defined by {} or
		function calls. If a class is not saved anywhere, it can be destructed immediatelly
		The compiler infuses the needed code for that

	*/

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}

