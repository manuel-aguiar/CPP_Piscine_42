/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:18:32 by codespace         #+#    #+#             */
/*   Updated: 2024/04/24 16:18:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"

#include <iostream>
#include <ctime>
#include <map>
#include <string>
#include <exception>
#include <fstream>
#include <sstream>


int main()
{


    try
    {
        BitcoinExchange btc;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
