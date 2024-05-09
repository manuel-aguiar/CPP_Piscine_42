/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:51:24 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 15:41:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <limits>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& assign);

		void	readInputFile(char *file_location);

	private:

	    typedef long int                _date_t;
	    std::map<_date_t,float>         _database;

	    void        loadDataBase(void);
	    void        printDataBase(void);
		void		insertDataBase(const _date_t date, const float price, const int& line_number);

		bool 		_validateDate(tm& timestruct);
	    _date_t    	_dateToLong(const std::string& datestr, const int& line_number);
		_date_t    	_dateToLong(const std::string& datestr);
		void		_checkInputFileHeader(const std::string& buffer);

	    class DataBaseException : public std::exception
	    {
	        public:
	            DataBaseException(const size_t whatLine, const std::string& whatError) throw();
	            ~DataBaseException() throw ();
	            const char *what() const throw();
	        private:
	            std::string     msg;
	    };

	    class InputFileException : public std::exception
	    {
	        public:
	            InputFileException(const std::string& whatError) throw();
	            ~InputFileException() throw ();
	            const char *what() const throw();
	        private:
	            std::string     msg;
	    };

	    class BadInputException : public std::exception
	    {
	        public:
	            BadInputException(const std::string& argument) throw();
	            ~BadInputException() throw ();
	            const char *what() const throw();
	        private:
	            std::string     msg;
	    };

};

/* Display message on STDERR.  */
#define CERR(x) std::cerr << (x) << std::endl



#endif
