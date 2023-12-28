/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_helper.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:51:23 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:54:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

bool     PhoneBook::my_atoi(std::string& str, int& place_res, int& contact_count)
{
	int res;
	int iter;

	res = 0;
	iter = 0;
	while (str[iter] && std::isspace(str[iter]))
		iter++;
	if (str[iter] && str[iter] == '-')
		return (false);
	if (str[iter] && str[iter] == '+')
		iter++;
	if (!str[iter] || (str[iter] && !std::isdigit(str[iter])))
		return (false);
	while (str[iter] && std::isdigit(str[iter]))
	{
		res = res * 10 + str[iter] - '0';
		if (res > contact_count - 1)
			return (false);
		iter++;
	}
	if (str[iter] && !std::isspace(str[iter]))
		return (false);
	place_res = res;
	return (true);
}



bool PhoneBook::buffer_is_only_space(std::string &buffer)
{
	std::string::size_type  i;
	std::string::size_type  len;

	len = buffer.size();
	for (i = 0; i < len; i++)
	{
		if (!std::isspace(buffer[i]))
			return (false);
	}
	return (true);
}

int	PhoneBook::string_to_action(std::string& buffer)
{
	if (!buffer.compare(ACT_ADD))
		return (ENU_ADD);
	if (!buffer.compare(ACT_SEARCH))
		return (ENU_SEARCH);
	if (!buffer.compare(ACT_EXIT))
		return (ENU_EXIT);
	if (!buffer.compare(ACT_HELP))
		return (ENU_HELP);
	return (ENU_ERROR);
}
