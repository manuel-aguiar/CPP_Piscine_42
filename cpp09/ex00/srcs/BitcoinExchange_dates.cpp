/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_dates.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:55 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 16:40:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"


//   https://stackoverflow.com/questions/36229110/c-month-day-and-year-validation

bool BitcoinExchange::_validateDate(tm& timestruct)
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

bool	BitcoinExchange::_validate_date_chars(const std::string& datestr)
{
	(void)datestr;
	return true;
}

BitcoinExchange::_date_t    BitcoinExchange::_dateToLong(const std::string& datestr, const int& line_number)
{
    int year, month, day;
    char delim;
    struct tm timeinfo;
    std::stringstream ss(datestr);

	delim = 0;
    ss >> year >> delim >> month >> delim >> day;
    if (ss.fail())			// unprotected for the stream having characters still;
    {
        throw DataBaseException(line_number,
        "date is not correctly formated.");
    }
	delim = 0;
	ss >> delim;
	if (delim != 0)
	{
        throw DataBaseException(line_number,
        "date is not correctly formated.");
    }
    std::memset(&timeinfo, 0, sizeof(timeinfo));
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    if (!_validateDate(timeinfo))
        throw DataBaseException(line_number,
        "date is not a valid calendar date.");
    return (std::difftime(std::mktime(&timeinfo), 0) / (60 * 60 * 24));
}

void    BitcoinExchange::loadDataBase(void)
{
    int line_number = 0;

    std::ifstream infile("data.csv");
    if (!infile.is_open())
        throw InputFileException(
        "file 'data.csv' is not available in the current directory.");

    std::string         buffer;
    std::string         datestr;

    std::getline(infile, buffer);
    ++line_number;
    while (!infile.eof())
    {
        ++line_number;
        std::getline(infile, buffer);
        if (infile.eof() && buffer.size() == 0)
            break ;
        std::stringstream   ss(buffer);
        std::getline(ss, datestr, ',');
        if(ss.peek() == EOF)
            throw DataBaseException(line_number,
        "database incomplete input.");
        long datenum = _dateToLong(datestr, line_number);
        float   price;
        ss >> price;

        if (ss.fail())
            throw DataBaseException(line_number,
                "price is not correctly formated.");
		char dummy;
		dummy = 0;
		ss >> dummy;
		if (dummy != 0)
			throw DataBaseException(line_number,
                "price is not correctly formated.");

        if (static_cast<long>(price) > std::numeric_limits<int>::max())
            throw DataBaseException(line_number,
                "too large a number");
        if (price < 0)
            throw DataBaseException(line_number,
                "not a non-negative number");

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
