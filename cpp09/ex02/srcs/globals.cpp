/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:06:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 16:17:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<
	typename T
>
std::string	getAllContainerNames() {
	return typeid(T).name();
}

const std::string	g_type_info[5] =
{
	getAllContainerNames<std::vector		<unsigned int> >(),
	getAllContainerNames<std::list			<unsigned int> >(),
	getAllContainerNames<std::deque			<unsigned int> >(),
	getAllContainerNames<std::multiset		<unsigned int> >(),
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
