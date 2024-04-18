/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:25 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 16:43:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
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

template<class T>
struct print_tester
{
	void operator()(const T& ref)
	{
		std::cout << ref << std::endl;
	}
};


int main(void)
{

	MutantStack<int, std::vector<int> > cenas;

	MutantStack<int, std::list<int> > tretas;

	tretas.push(1);
	tretas.push(2);
	tretas.push(3);
	tretas.push(4);
	tretas.push(5);

	std::for_each(tretas.begin(), tretas.end(), print_tester<int>());



	/*
	std::stack<int, std::deque<int> > deque_stack;

	std::stack<int, std::list<int> > list_stack;

	std::stack<int, std::vector<int> > vector_stack;
	*/
	return (0);
}
