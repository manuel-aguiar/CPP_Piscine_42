/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/26 17:03:20 by manuel           ###   ########.fr       */
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

BitcoinExchange::DataBaseException::DataBaseException(const size_t whatLine, const std::string& whatError) throw()
{
	std::stringstream ss;

	ss << whatLine;
	msg = "Error: database at line "
		+ ss.str()
		+ ": "
		+ whatError;
}

BitcoinExchange::DataBaseException::~DataBaseException() throw () {}

const char* BitcoinExchange::DataBaseException::what() const throw()
{
	return (msg.c_str());
}

BitcoinExchange::InputFileException::InputFileException(const std::string& whatError) throw()
{
	msg = "Error: " + whatError;
}

BitcoinExchange::InputFileException::~InputFileException() throw () {}

const char* BitcoinExchange::InputFileException::what() const throw()
{
	return (msg.c_str());
}

BitcoinExchange::BadInputException::BadInputException(const std::string& argument) throw()
{
	msg = "Error: bad input => " + argument;
}

BitcoinExchange::BadInputException::~BadInputException() throw () {}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return (msg.c_str());
}
