/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:28 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 10:52:22 by codespace        ###   ########.fr       */
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
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c (2);

	std::cout << (c > 0) << std::endl;		// default constructor applied to "0", zero is promoted to class "Fixed"
	std::cout << (c * 2.5f) << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

