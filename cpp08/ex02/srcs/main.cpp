/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:25 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 16:01:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <ctime>
#include <cstdlib>

int	call_srand(void)
{
	std::srand(std::time(0));
	return (1);
}

int g_rand = call_srand();

int main(void)
{
	std::stack<int, std::deque<int> > deque_stack;

	std::stack<int, std::list<int> > list_stack;

	std::stack<int, std::vector<int> > vector_stack;

	return (0);
}
