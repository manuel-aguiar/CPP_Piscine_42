/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:25 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 15:55:59 by codespace        ###   ########.fr       */
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
#include <iomanip>

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


template <
	class T,
	class C = std::deque<T>
>
class Tester
{
	public:
		Tester() {}
		~Tester() {}

		void	push(const T& target)
		{
			mutant.push(target);
			list.push_back(target);
			deque.push_back(target);
			vector.push_back(target);
		}

		void	print_top(void)
		{
			std::cout 	<< "Top print: "  << " | "
						<< std::left << std::setw(10) << mutant.top() << " | "
						<< std::left << std::setw(10) << *list.rbegin() << " | "
						<< std::left << std::setw(10) << *deque.rbegin() << " | "
						<< std::left << std::setw(10) << *vector.rbegin() << " | "
						<< std::left << std::setw(10) << std::endl;
		}

		void	pop(void)
		{
			mutant.pop();
			list.pop_back();
			deque.pop_back();
			vector.erase(vector.rbegin());
		}

		void	print_size(void)
		{
			std::cout 	<< "Print size: "  << " | "
						<< std::left << std::setw(10) << mutant.size() << " | "
						<< std::left << std::setw(10) << list.size() << " | "
						<< std::left << std::setw(10) << deque.size() << " | "
						<< std::left << std::setw(10) << vector.size() << " | "
						<< std::left << std::setw(10) << std::endl;
		}

		void	print_stack(void)
		{
			typename MutantStack<T,C>::iterator ms_it = mutant.begin();
			typename MutantStack<T,C>::iterator ms_ite = mutant.end();

			++ms_it;
			--ms_it;

			typename std::list<T>::iterator list_it = list.begin();
			typename std::list<T>::iterator list_ite = list.end();

			typename std::deque<T>::iterator deque_it = deque.begin();
			typename std::deque<T>::iterator deque_ite = deque.end();

			typename std::vector<T>::iterator vector_it = vector.begin();
			typename std::vector<T>::iterator vector_ite = vector.end();

			std::cout 	<< "\nFull stack print: " << std::endl;
			while (ms_it != ms_ite)
			{
				std::cout 	<< std::left << std::setw(10) << *ms_it << " | "
							<< std::left << std::setw(10) << *list_it << " | "
							<< std::left << std::setw(10) << *deque_it << " | "
							<< std::left << std::setw(10) << *vector_it << " | "
							<< std::left << std::setw(10) << std::endl;

				++ms_it;
				++list_it;
				++deque_it;
				++vector_it;
			}
			if (list_it != list_ite || deque_it != deque_ite || vector_it != vector_ite)
				std::cout << "Ops sizes don't match..." << std::endl;
			std::cout 	<< "Full stack end print\n" << std::endl;
		}

		void	print_stack_reverse(void)
		{
			typename MutantStack<T,C>::reverse_iterator ms_it = mutant.rbegin();
			typename MutantStack<T,C>::reverse_iterator ms_ite = mutant.rend();

			++ms_it;
			--ms_it;

			typename std::list<T>::reverse_iterator list_it = list.rbegin();
			typename std::list<T>::reverse_iterator list_ite = list.rend();

			typename std::deque<T>::reverse_iterator deque_it = deque.rbegin();
			typename std::deque<T>::reverse_iterator deque_ite = deque.rend();

			typename std::vector<T>::reverse_iterator vector_it = vector.rbegin();
			typename std::vector<T>::reverse_iterator vector_ite = vector.rend();

			std::cout 	<< "\nFull stack reverse print: " << std::endl;
			while (ms_it != ms_ite)
			{
				std::cout 	<< std::left << std::setw(10) << *ms_it << " | "
							<< std::left << std::setw(10) << *list_it << " | "
							<< std::left << std::setw(10) << *deque_it << " | "
							<< std::left << std::setw(10) << *vector_it << " | "
							<< std::left << std::setw(10) << std::endl;

				++ms_it;
				++list_it;
				++deque_it;
				++vector_it;
			}
			if (list_it != list_ite || deque_it != deque_ite || vector_it != vector_ite)
				std::cout << "Ops sizes don't match..." << std::endl;
			std::cout 	<< "Full stack reverse print end\n" << std::endl;
		}

		const MutantStack<T,C>&	get_mutant(void) const
		{
			return (mutant);
		}

	private:
		MutantStack<T,C>	mutant;
		std::list<T>		list;
		std::deque<T>		deque;
		std::vector<T>		vector;

		Tester(const Tester& copy) {(void)copy;}
		Tester& operator=(const Tester& assign) {(void)assign; return (*this);}
};


int main(void)
{
	try
	{
		/* oh yeah boy massive try catch around EVERYTHING */

		std::cout << "**********************************" << std::endl;
		std::cout << "School Main [mutantstack | std::list | std::deque(stack) | std::vector] \n" << std::endl;

		/*
			You can't have a container of const types because containers require them to be move assignable

			chatgpt hack:
				std::list<std::shared_ptr<const int>> my_list;
				my_list.push_back(std::make_shared<const int>(5));
				my_list.push_back(std::make_shared<const int>(10));

		*/


		{
			Tester<int> tester;

			tester.push(5);
			tester.push(17);
			tester.print_top();
			tester.print_stack();
			tester.push(3);
			tester.push(5);
			tester.push(737);
			tester.push(0);
			tester.print_size();
			tester.print_top();
			tester.print_stack();

			std::stack<int> s(tester.get_mutant());
			std::cout << "std::stack copy, " << s.top() << ", size: " << s.size() << std::endl;

		}

		/*
			The stack's beginning iterator points to the bottom while rbegin points to the top
			Makes sense to save space, moving fewer pointers and, in case of a vector stack
			to avoid all the copying from inserting at the front.
			So, when iterating through a stack, ideally you should start on rbegin to rend :D

			In a way, you can say that visually, the stack grows... downwards...?
		*/

		std::cout << "**********************************" << std::endl;
		std::cout << "School Main [mutantstack | std::list | std::deque(stack) | std::vector]" << std::endl;
		std::cout << "	but this time: mutant of std::string, mutant as a vector and reverse_print\n" << std::endl;

	/*
		You can't have a container of const types because containers require them to be move assignable

		chatgpt hack:
			std::list<std::shared_ptr<const int>> my_list;
			my_list.push_back(std::make_shared<const int>(5));
			my_list.push_back(std::make_shared<const int>(10));

	*/


		{
			Tester<std::string, std::vector<std::string> > tester;

			tester.push("batatas");
			tester.push("cenouras");
			tester.print_top();
			tester.print_stack_reverse();
			tester.push("couves");
			tester.push("cajus");
			tester.push("trigo");
			tester.push("azeitonas");
			tester.print_size();
			tester.print_top();
			tester.print_stack_reverse();

			std::stack<std::string, std::vector<std::string> > s(tester.get_mutant());
			std::cout << "std::stack copy, top: " << s.top() << ", size: " << s.size() << std::endl;
		}

		std::cout << "\n**********************************" << std::endl;
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

			MutantStack<int> cenas;
			cenas = tretas;
			std::cout << "	Printing assignment" << std::endl;
			std::for_each(cenas.begin(), cenas.end(), print_tester<int>());

			MutantStack<int> coisas(cenas);
			std::cout << "	Printing copy construction" << std::endl;
			std::for_each(coisas.begin(), coisas.end(), print_tester<int>());
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

			MutantStack<int, std::vector<int> > cenas;
			cenas = tretas;
			std::cout << "	Printing assignment" << std::endl;
			std::for_each(cenas.begin(), cenas.end(), print_tester<int>());

			MutantStack<int, std::vector<int> > coisas(cenas);
			std::cout << "	Printing copy construction" << std::endl;
			std::for_each(coisas.begin(), coisas.end(), print_tester<int>());
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);



}
