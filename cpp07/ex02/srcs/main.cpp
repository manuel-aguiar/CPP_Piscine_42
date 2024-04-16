/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:06 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 15:37:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main(void)
{
	Array<int> arr(10);
	arr[1] = 42;
	std::cout << arr[1] << std::endl;
	Array<int> copy(arr);
	copy[1] = 24;
	std::cout << arr[1] << std::endl;


	Array<int> bigger(24);

	bigger = arr;
	std::cout << bigger.size() << std::endl;
	try
	{
		bigger[23] = 38;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
