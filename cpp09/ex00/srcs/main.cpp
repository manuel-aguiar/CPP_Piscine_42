/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:18:32 by codespace         #+#    #+#             */
/*   Updated: 2024/04/26 14:59:24 by manuel           ###   ########.fr       */
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


int main(int ac, char **av)
{
    if (ac != 2)
    {
        CERR("Error: wrong number of input files");
        return (0);
    }
    try
    {
        BitcoinExchange btc;
        btc.readInputFile(av[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
