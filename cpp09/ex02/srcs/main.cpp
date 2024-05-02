/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/02 15:56:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

#include <string>


int main(int ac, char **av)
{
	try
	{
		MergeInsertComp<> comp(--ac, ++av);
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
