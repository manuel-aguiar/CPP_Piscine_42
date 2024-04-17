/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:20:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/17 13:18:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(void)
{


	{
		std::map<int, std::string> map;

		map[5] = "tretas";
		map[1] = "tretas";
		map[4] = "tretas";
		map[2] = "tretas";
		map[6] = "tretas";

		int target = 7;

		try
		{
			std::map<int, std::string>::iterator it = easyfind(map, target);
			std::pair<const int, std::string>& pair = *it;
			std::cout << "map find " << pair.first << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}



	}


	std::cout << "generic easyfind" << std::endl;
	{
		std::map<std::string, int> map;

		map["cenas"] = 3;
		map["tretas"] = 2;
		map["coisas"] = 5;
		map["templates"] = 4;
		map["yaya"] = 10;

		std::string target = "templates";

		try
		{
			std::map<std::string, int>::iterator it = generic_easyfind(map, target);
			std::pair<const std::string, int>& pair = *it;
			std::cout << "map find " << pair.first << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

/*
{
    std::vector<int> vector;
    vector.push_back(5);
    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(5);
    vector.push_back(7);
    int  target(5);

	int res = *easyfind(vector, target);

	std::cout << res << std::endl;
}

{
    std::string container("tretas");

    int target = 65;

	int res = *easyfind(container, target);

	std::cout << res << std::endl;
}

{
    std::vector<std::string> vector;
    vector.push_back("cenas");
    vector.push_back("tretas");
    vector.push_back("coisas");
    vector.push_back("existencias");
    vector.push_back("yolo");
    std::string  target("tretas");

	std::string res = *generic_easyfind(vector, target);
}
*/

	return (0);
}
