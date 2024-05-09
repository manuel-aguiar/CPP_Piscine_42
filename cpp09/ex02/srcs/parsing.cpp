/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 08:42:17 by codespace        ###   ########.fr       */
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
