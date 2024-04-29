/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:25 by codespace         #+#    #+#             */
/*   Updated: 2024/04/29 14:19:10 by codespace        ###   ########.fr       */
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

#include "../../ex00/incs/easyfind.hpp"

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
	std::cout << "**********************************" << std::endl;
	std::cout << "Mutant Stack, specifiying type\n" << std::endl;
	{
		MutantStack<int> tretas;

		tretas.push(1);
		tretas.push(2);
		tretas.push(3);
		tretas.push(4);
		tretas.push(5);

		std::cout << "size of stack: " << tretas.size() << ", print: " << std::endl;
		std::for_each(tretas.begin(), tretas.end(), print_tester<int>());
	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Mutant Stack, specifiying type and the underlying container as a vector\n" << std::endl;
	{
		MutantStack<int, std::vector<int> > tretas;

		tretas.push(3);
		tretas.push(1);
		tretas.push(36);
		tretas.push(43);
		tretas.push(8);

		std::cout << "print: " << std::endl;
		std::for_each(tretas.begin(), tretas.end(), print_tester<int>());

		std::cout 	<< "Since vector's iterator are random access, one could use std::sort\n"
					<< "Would work as well under std::deque, BUT not if we use std::list:\n"
					<< "	- lists are not contiguous in memory and so, don't support O(1) random access\n"
					<< "	- Deques have an array of pointers to each block, so they solve random access with\n"
					<< "	pointer arithmatic. Couple more operations then vector but still constant time" << std::endl;

		std::cout	<< "blablabla time to sort:" << std::endl;
		std::sort(tretas.begin(), tretas.end());
		std::for_each(tretas.begin(), tretas.end(), print_tester<int>());

		std::cout << "oh yeah" << std::endl;
	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Now, try the same thing with std::list as a base container for std::stack:" << std::endl;
	std::cout 	<< "Spoiler alert: doesn't compile because std::list iterators are not random access\n"
				<< "as requested by std::sort\n"
				<< "Unfortunately, the stack doesn't inherit the std::list::sort() method.. is there a way?\n\n";

	std::cout 	<< "template<\n"
				<<	"	class T,\n"
				<<	"	class C\n"
				<<	">	void MutantStack<T,C>::sort(void)\n"
				<<	" 	{\n"
				<<	"		return (std::stack<T,C>::c.sort());\n"
				<<	" 	}\n";
	std::cout 	<< "\ntrying to call mutantstack.sort() when the underlying is not a list, would not compile\n"
				<< "and i can't risk that in evaluation :D but this works"
				<< std::endl;

	std::cout << "**********************************" << std::endl;
	std::cout << "Ok let's print the stack backwards\n" << std::endl;
	{
		MutantStack<int, std::vector<int> > tretas;

		tretas.push(3);
		tretas.push(1);
		tretas.push(36);
		tretas.push(43);
		tretas.push(8);

		std::cout << "print forward: " << std::endl;
		std::for_each(tretas.begin(), tretas.end(), print_tester<int>());
		std::cout << "print backward: " << std::endl;
		std::for_each(tretas.rbegin(), tretas.rend(), print_tester<int>());

		std::cout << "oh yeah" << std::endl;

		std::cout 	<< "rbegin() means, the first element of the reversed container\n"
					<< "so essentially, the last element in the forward container\n"
					<< "same for rend(), so we essentially print backwards\n"
					<< "internally, i assume the operator++ decrements the pointer\n"
					<< "and that is the operator std::for_each needs to move"
					<< std::endl;
	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Let's borrow easyfind from ex00 to see if it works (uses iterators)\n" << std::endl;

	{
		MutantStack<int> tretas;

		tretas.push(3);
		tretas.push(1);
		tretas.push(36);
		tretas.push(43);
		tretas.push(8);

		MutantStack<int>::const_iterator iter = easyfind(tretas, 43);

		std::cout << "found it! " << *iter << std::endl;
	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Let's borrow easyfind from ex00 to see if it works (uses iterators)\n" << std::endl;

	{
		MutantStack<int> tretas;

		tretas.push(3);
		tretas.push(1);
		tretas.push(36);
		tretas.push(43);
		tretas.push(8);

		MutantStack<int>::const_iterator iter = easyfind(tretas, 43);

		std::cout << "found it! " << *iter << std::endl;
	}

	return (0);
}
