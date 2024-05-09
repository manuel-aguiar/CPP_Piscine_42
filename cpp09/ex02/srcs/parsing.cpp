/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 13:22:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool is_only_spaces(const std::string& word)
{
	for (size_t i = 0; i < word.length(); i++)
	{
		if (!(word[i] == '\n'
		|| word[i] == '\t'
		|| word[i] == '\v'
		|| word[i] == ' '
		|| word[i] == '\b'))
			return (false);
	}
	return (true);
}

void	print_num(const unsigned int num)
{
	std::cout << num << " ";
}
