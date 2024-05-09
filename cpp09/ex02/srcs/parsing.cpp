/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 08:47:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
std::string	getAllContainerName() {
	return typeid(T).name();
}

const std::string	g_type_info[5] =
{
	getAllContainerName<std::vector<int> >(),
	getAllContainerName<std::list<int> >(),
	getAllContainerName<std::deque<int> >(),
	getAllContainerName<std::multiset<int> >(),
	"Unnallowed"
};

const std::string	g_type_name[5] =
{
	"std::vector",
	"std::list",
	"std::deque",
	"std::multiset",
	"Unnallowed"
};

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
