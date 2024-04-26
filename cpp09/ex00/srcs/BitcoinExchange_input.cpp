/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_input.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:33 by manuel            #+#    #+#             */
/*   Updated: 2024/04/26 16:18:43 by manuel           ###   ########.fr       */
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
    //std::cout << "year: " << year << ", month : " << month << ", day: " << day << std::endl;
    if (ss.fail())			// unprotected for the stream having characters still;
    {
        throw InputFileException("date is not correctly formated.");
    }
    std::memset(&timeinfo, 0, sizeof(timeinfo));
    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1;    // Months are 0-based
    timeinfo.tm_mday = day;         // Day of the month
    if (!_validateDate(timeinfo))
        throw InputFileException("date is not a valid calendar date.");
    return (std::difftime(std::mktime(&timeinfo), 0) / (60 * 60 * 24)); // Convert to days since epoch
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
            if (infile.eof())       //potential mistake, EOF may not be on a newline
                break ;
            std::stringstream   ss(buffer);
            std::getline(ss, datestr, '|');
            long datenum = _dateToLong(datestr);
            float   price;
            ss >> price;
            if (ss.fail())				// unprotected for the stream having characters still;
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