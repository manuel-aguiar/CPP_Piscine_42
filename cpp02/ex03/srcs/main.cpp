/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:57:16 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 12:24:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"


int main( void )
{
	Vector a(0, 0);
	Vector b(0, 10);
	Vector c(10, 0);

	Vector target(5, 5);

	std::cout << "Point in triangle? " << (bsp(target, a, b, c) == 1 ? "Yes" : "No") << std::endl;

	return (0);
}

