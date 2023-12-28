/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:57:16 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:57:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"


int main( void )
{
	Point a(0, 0);
	Point b(0, 100);
	Point c(100, 0);

	Point target(0,0);

	std::cout << "Point in triangle? " << (bsp(target, a, b, c) == 1 ? "Yes" : "No") << std::endl;

	return (0);
}

