/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/03 11:26:22 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

#include <string>

/*
	This.. is... the painkiiii......   super convoluted code.
	I'm sorry to my evaluators.
	Most of this is totally useless, all this template stuff
	Don't do it.
	I'm doing it because we are in school and this is the time to explore.
	But don't, please.
*/

int main(int ac, char **av)
{
	try
	{
		MergeInsertComp<unsigned int, std::deque, std::list> comp(--ac, ++av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}

/*
	./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`
*/
