/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:46:23 by manuel            #+#    #+#             */
/*   Updated: 2024/04/22 09:10:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
    {
        int i = 5;
        int j = 6;

        std::cout << "i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "i: " << i << " j: " << j << std::endl;
		std::cout << "max is: " << max(i, j) << std::endl;
		std::cout << "min is: " << min(i, j) << std::endl;
    }

    {
        std::string i("tretas");
        std::string j("cenas");

        std::cout << "i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "i: " << i << " j: " << j << std::endl;
		std::cout << "max is: " << max(i, j) << std::endl;
		std::cout << "min is: " << min(i, j) << std::endl;
    }

    {
        float i = 1.50e+38;
        float j = 5.0e+20;

        std::cout << "i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "i: " << i << " j: " << j << std::endl;
		std::cout << "max is: " << max(i, j) << std::endl;
		std::cout << "min is: " << min(i, j) << std::endl;
    }
}
