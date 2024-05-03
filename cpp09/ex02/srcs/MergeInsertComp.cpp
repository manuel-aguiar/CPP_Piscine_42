/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertComp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:35:14 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 09:52:34 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

//helper functions
int	is_only_spaces(std::string& word)
{
	for (std::string::iterator iter = word.begin(); iter != word.end(); ++iter)
	{
		if (*iter != '\n'
		&& *iter != '\t'
		&& *iter != '\v'
		&& *iter != ' '
		&& *iter != '\b')
			return (false);
	}
	return (true);
}