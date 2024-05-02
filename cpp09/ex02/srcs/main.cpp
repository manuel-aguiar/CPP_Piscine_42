/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/05/02 15:48:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsertComp.hpp"

#include <string>


int main(int ac, char **av)
{
	MergeInsertComp<> comp(--ac, ++av);

    return (0);
}

/*
	./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`
*/
