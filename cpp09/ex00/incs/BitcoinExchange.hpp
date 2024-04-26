/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:51:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/26 14:51:21 by manuel           ###   ########.fr       */
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

#include "DataBase.tpp"

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

		//helper methods
	    long    dateToLong(const std::string& datestr, const int& line_number);



	    class DataBaseException : public std::exception
	    {
	        public:
	            DataBaseException(const size_t whatLine, const std::string& whatError) throw()
	            {
	                std::stringstream ss;

	                ss << whatLine;
	                msg = "Error: database at line "
	                    + ss.str()
	                    + ": "
	                    + whatError;
	            }

	            ~DataBaseException() throw () {}
	            const char *what() const throw()
	            {
	                return (msg.c_str());
	            }
	        private:
	            std::string     msg;
	    };

	    class InputFileException : public std::exception
	    {
	        public:
			
	            InputFileException(const std::string& whatError) throw()
	            {
	                msg = "Error: " + whatError;
	            }

	            ~InputFileException() throw () {}

	            const char *what() const throw()
	            {
	                return (msg.c_str());
	            }
				
	        private:
	            std::string     msg;
	    };

};

/* Display message on STDERR.  */
#define CERR(x) std::cerr << (x) << std::endl






#endif
