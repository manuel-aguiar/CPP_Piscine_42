/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/09 15:10:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

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
		MergeInsertComp<int, std::deque, std::list, FordJohnsonFunctor> comp(--ac, ++av);
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


