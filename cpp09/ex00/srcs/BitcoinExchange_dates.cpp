/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_dates.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:55 by codespace         #+#    #+#             */
/*   Updated: 2024/04/26 15:05:34 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"


//   https://stackoverflow.com/questions/36229110/c-month-day-and-year-validation

bool validateDate(tm& timestruct)
{
    struct tm copy;

    std::memcpy(&copy, &timestruct, sizeof(timestruct));
    std::mktime(&copy);
    if (copy.tm_mday != timestruct.tm_mday
    || copy.tm_mon != timestruct.tm_mon
    || copy.tm_year != timestruct.tm_year)
        return (false);
    return (true);
}

long    BitcoinExchange::dateToLong(const std::string& datestr, const int& line_number)
{
    int year, month, day;
    char delim;
    struct tm timeinfo;
    std::stringstream ss(datestr);

    ss >> year >> delim >> month >> delim >> day;
    //std::cout << "year: " << year << ", month : " << month << ", day: " << day << std::endl;
    if (ss.fail())			// unprotected for the stream having characters still;
    {
        throw BitcoinExchange::DataBaseException(line_number,
        "date is not correctly formated.");
    }
    std::memset(&timeinfo, 0, sizeof(timeinfo));
    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1;    // Months are 0-based
    timeinfo.tm_mday = day;         // Day of the month
    if (!validateDate(timeinfo))
        throw DataBaseException(line_number,
        "date is not a valid calendar date.");
    return (std::difftime(std::mktime(&timeinfo), 0) / (60 * 60 * 24)); // Convert to days since epoch
}

void    BitcoinExchange::loadDataBase(void)
{
    int line_number = 0;

    std::ifstream infile("data.csv");
    if (!infile.is_open())
        throw DataBaseException(line_number,
        "file 'data.csv' is not available in the current directory.");

    std::string         buffer;
    std::string         datestr;

    //dump the header;
    std::getline(infile, buffer);
    ++line_number;

    while (!infile.eof())
    {
        ++line_number;
        std::getline(infile, buffer);
        if (infile.eof())       //potential mistake, EOF may not be on a newline
            break ;
        std::stringstream   ss(buffer);
        std::getline(ss, datestr, ',');
        long datenum = dateToLong(datestr, line_number);
        float   price;
        ss >> price;
        if (ss.fail())				// unprotected for the stream having characters still;
            throw DataBaseException(line_number,
        "price is not correctly formated.");
        
        insertDataBase(datenum, price, line_number);
    }


    infile.close();
}

void    BitcoinExchange::printDataBase(void)
{
    for (std::map<_date_t, float>::iterator iter = _database.begin(); iter != _database.end(); ++iter)
    {
        std::cout << "date: " << iter->first << ", price:  " << iter->second << std::endl;
    }
}

void    BitcoinExchange::insertDataBase(const _date_t date, const float price, const int& line_number)
{
    std::pair<std::map <_date_t, float>::iterator , bool>
    entry = _database.insert(std::make_pair(date, price));
    if (entry.second == false)
        throw DataBaseException(line_number, "doubled database entry.");
}

void    BitcoinExchange::readInputFile(char *file_location)
{
    std::ifstream infile(file_location);
    if (!infile.is_open())
        throw InputFileException("failed to open the file");
    
    std::string         buffer;
    std::string         datestr;
    int                 line_number = 0;
    //dump the header;
    std::getline(infile, buffer);

    while (!infile.eof())
    {
        try
        {
            std::getline(infile, buffer);
            if (infile.eof())       //potential mistake, EOF may not be on a newline
                break ;
            std::stringstream   ss(buffer);
            std::getline(ss, datestr, '|');
            long datenum = dateToLong(datestr, line_number);
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