/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:09:33 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 13:48:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
/*
int main(void)
{
	Fixed a (0);
	Fixed b (10.1f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << --a << std::endl;

	return (0);
}
*/

int main( void )
{
	//Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c (2);

	std::cout << (c > 0) << std::endl;		// default constructor applied to "0", zero is promoted to class "Fixed"

	//std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

