/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/26 16:11:11 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "BitcoinExchange Constructor called" << std::endl;
	#endif

	loadDataBase();
	//printDataBase();
}

BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "BitcoinExchange Destructor called" << std::endl;
	#endif
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "BitcoinExchange Copy Constructor called" << std::endl;
	#endif
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "BitcoinExchange Copy Assignment called" << std::endl;
	#endif
	(void)assign;
	return (*this);
}