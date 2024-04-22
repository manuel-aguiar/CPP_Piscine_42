/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:46:23 by manuel            #+#    #+#             */
/*   Updated: 2024/04/22 10:00:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{

    {
        int i = 5;
        int j = 6;


		int max = ::max(i, j);
		int min = ::min(i, j);
		std::cout << "max is: " << max << std::endl;
		std::cout << "min is: " << min << std::endl;

        std::cout << "i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "i: " << i << " j: " << j << std::endl;
    }


    {
        std::string i("tretas");
        std::string j("cenas");


		std::string& max = ::max(i, j);
		std::string& min = ::min(i, j);

		std::cout << "max is: " << max << std::endl;
		std::cout << "min is: " << min << std::endl;

		i = "hiphop";
		std::cout << "min is: " << min << std::endl;

        std::cout << "before swap i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "after swap  i: " << i << " j: " << j << std::endl;

    }


    {
        float i = 1.50e+38;
        float j = 5.0e+20;


		float max = ::max(i, j);
		float& max_ref = ::max(i, j);
		float min = ::min(i, j);
		std::cout << "max is: " << max << " max_ref: " << max_ref << std::endl;
		std::cout << "min is: " << min << std::endl;

        std::cout << "i: " << i << " j: " << j << std::endl;
        swap(i, j);
        std::cout << "i: " << i << " j: " << j << std::endl;
    }

}
