/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:00:26 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 13:49:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main(int ac, char **av)
{
    if (ac != 4)
    {
		std::cout << "Bad number of inputs" << std::endl;
		return (0);
    }

    //necessary variables
    std::string out_name = std::string(av[1]) + ".replace";
    std::string buffer;
    std::string temp;
    std::string str_search = av[2];
    std::string str_replace = av[3];
    size_t      start;
    size_t      index;
    size_t      len;

    //preparing files and open error checking
    std::remove(out_name.c_str());
    std::ifstream infile(av[1]);
    std::ofstream outfile(out_name.c_str());

    if (!infile.is_open())
    {
		std::cerr << "Error: infile open failed" << std::endl;
		return (1);
    }
    if (!outfile.is_open())
    {
		std::cerr << "Error: outfile open failed" << std::endl;
		infile.close();
		return (1);
    }

    // main block
    len = str_search.size();
	if (len == 0)
	{
    	infile.close();
    	outfile.close();
   		return (0);
	}
    start = 0;
    index = 0;
    while (std::getline(infile, temp))
    {
		//Getline "extracts and discards" the '\n', if it finds a '\n',
		//it will stop there but won't receive an eof indication.
		//So, no eof means there is a newline that was discarded.
		//Add it back to the string cause it may be part of the "str_search".
		if (!infile.eof())
	    	temp += "\n";

		// merge the leftovers of the buffer with what was read now
		buffer = buffer.substr(start) + temp;
		start = 0;
		index = 0;
		while (1)
		{
	    	// moved past the buffer, ask for more characters from std::getline
	    	if (start >= buffer.size())
				break ;

	    	// find str_search in the buffer
	    	index = buffer.find(str_search, start);
	    	if (index != std::string::npos)
	    	{
				outfile << buffer.substr(start, index - start);
				outfile << str_replace;
				start += (index - start + len);
	    	}
	    	//str_search wasn't found, but "\n" may be a part of the substring
	    	//dump all except len of str_search to guarantee you don't cut a
	    	//potential candidate in half
	    	else if (start + len < buffer.size())
	    	{
				outfile << buffer.substr(start, buffer.size() - len - start);
				start = buffer.size() - len;
				break ;
	    	}
	    	// buffer is smaller than len str_search, take no risks and ask for more
	    	// characters to std::getline
	    	else
				break ;
		}
    }
    // dump whatever is left on the buffer to outfile
    if (start < buffer.size())
		outfile << buffer.substr(start);

    //clean up
    infile.close();
    outfile.close();

    return (0);
}
