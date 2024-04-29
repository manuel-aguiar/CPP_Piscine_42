/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:08:50 by astein            #+#    #+#             */
/*   Updated: 2024/04/29 14:13:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

// COLORS
# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

void	title(std::string str, bool newline_before, bool newline_after)
{
	if (newline_before)
		std::cout << std::endl;
	std::cout << CLR_ORN <<
		">>> " << str << " <<<" <<
		CLR_RST << std::endl;
	if (newline_after)
		std::cout << std::endl;
}

void	info(std::string str, std::string clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}


int main()
{
	{
		title("START: modified 42 Test", true, false);
		MutantStack<int>	mstack;
		std::list<int>		list;
		mstack.push(5);
		list.push_back(5);
		mstack.push(17);
		list.push_back(17);
		std::cout << "TOP MINE: " << mstack.top() << std::endl;
		std::cout << "TOP LIST: " << list.back() << std::endl;
		mstack.pop();
		list.pop_back();
		std::cout << "SIZE MINE: " << mstack.size() << std::endl;
		std::cout << "SIZE LIST: " << list.size() << std::endl;
		mstack.push(3);
		list.push_back(3);
		mstack.push(5);
		list.push_back(5);
		mstack.push(737);
		list.push_back(737);
		mstack.push(0);
		list.push_back(0);
		MutantStack<int>::iterator it = mstack.begin();
		std::list<int>::iterator lit = list.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::list<int>::iterator lite = list.end();
		++it;
		++lit;
		--it;
		--lit;
		while (it != ite)
		{
			std::cout << "MINE: " << *it << std::endl;
			++it;
		}
		while (lit != lite)
		{
			std::cout << "LIST: " << *lit << std::endl;
			++lit;
		}
		info ("Try to convert MutantStack to std::stack", CLR_GRN);
		std::stack<int> s(mstack);
		title("END: modified 42 Test", false, true);
		info ("Try to convert MutantStack to std::list", CLR_GRN);
		std::list<int> l(mstack.begin(), mstack.end());
		info("Iterating through the list", CLR_GRN);
		for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << std::endl;

		title("Try reverse iterator incremeting all values", true, false);
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite)
		{
			(*rit)++;
			std::cout << "MINE: " << *rit << std::endl;
			++rit;
		}

		title("Try const iterators...", true, false);
		info("const_iterator", CLR_GRN);
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
		while (cit != cite)
		{
			// (*cit)++; // Doesn't compile since it's a const_iterator
			std::cout << "MINE: " << *cit << std::endl;
			++cit;
		}

		info("const_reverse_iterator", CLR_GRN);
		MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.rend();
		while (crit != crite)
		{
			// (*crit)++; // Doesn't compile since it's a const_iterator
			std::cout << "MINE: " << *crit << std::endl;
			++crit;
		}


	}
	return 0;
}
