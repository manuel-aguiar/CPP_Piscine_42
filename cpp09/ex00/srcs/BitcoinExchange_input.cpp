/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_input.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:33 by manuel            #+#    #+#             */
/*   Updated: 2024/04/26 16:35:52 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    BitcoinExchange::_checkInputFileHeader(const std::string& buffer)
{
    if (buffer != "date | value")
        throw InputFileException("database header must be 'date | value'");
}

long    BitcoinExchange::_dateToLong(const std::string& datestr)
{
    int year, month, day;
    char delim;
    struct tm timeinfo;
    std::stringstream ss(datestr);

    ss >> year >> delim >> month >> delim >> day;
    if (ss.fail())			// unprotected for the stream having characters still;
        throw InputFileException("date is not correctly formated.");
    std::memset(&timeinfo, 0, sizeof(timeinfo));
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    if (!_validateDate(timeinfo))
        throw InputFileException("date is not a valid calendar date.");
    return (std::difftime(std::mktime(&timeinfo), 0) / (60 * 60 * 24));
}

void    BitcoinExchange::readInputFile(char *file_location)
{
    std::ifstream infile(file_location);
    if (!infile.is_open())
        throw InputFileException("failed to open the file");
    
    std::string         buffer;
    std::string         datestr;
    
    std::getline(infile, buffer);
    _checkInputFileHeader(buffer);

    while (!infile.eof())
    {
        try
        {
            std::getline(infile, buffer);
            if (infile.eof() && buffer.size() == 0)
                break ;
            std::istringstream   ss(buffer);
            std::getline(ss, datestr, '|');
            if(ss.peek() == EOF)
                throw BadInputException(buffer);
            long datenum = _dateToLong(datestr);
            float   price;
            ss >> price;
            if (ss.fail() || ss.peek() != EOF)
                throw InputFileException("price is not correctly formated.");
            std::map<_date_t, float>::iterator iter = _database.lower_bound(datenum);
            if (iter == _database.end())
                --iter;
            std::cout << datestr << "=> " << price << " = " << price * iter->second << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }


    infile.close();
        
}