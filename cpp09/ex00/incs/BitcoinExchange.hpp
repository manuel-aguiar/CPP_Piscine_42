/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:51:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/24 16:15:57 by codespace        ###   ########.fr       */
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

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& assign);




	private:
	    void        loadDataBase(void);
	    void        printDataBase(void);
	    typedef long int                _date_t;
	    std::map<_date_t,float>         _database;

		//helper methods
	    long    dateToLong(std::string& datestr, const int& line_number);



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

};

/* Display message on STDERR.  */
#define CERR(x) std::cerr << (x) << std::endl






#endif
