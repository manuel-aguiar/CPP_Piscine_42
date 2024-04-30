/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 14:00:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <limits>

void    print_int(const int& n)
{
    std::cout << n << std::endl;
}

int main(void)
{

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "0-cap span:" << std::endl;
	{
		try
		{
			Span span(0);
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
			std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}


	std::cout << "\n*****************************************" << std::endl;
	std::cout << "1-cap span:" << std::endl;
	{

		try
		{
			Span span(1);
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
			std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Empty span:" << std::endl;
	{
		Span span(7);
		try
		{
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
			std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "1-element span:" << std::endl;
	{
		try
		{
			Span span(5);
			span.addNumber(1);
			long longest = span.longestSpan();
			long shortest = span.shortestSpan();
			std::cout << "Longest Span is: " << longest << std::endl;
			std::cout << "Shortest Span is: " << shortest << std::endl;
			if (longest != shortest)
				std::cout << "			longest and shortest ARE NOT THE SAME" << std::endl;
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
			std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Simple 2 number span:" << std::endl;
	{
		try
		{
			Span span(2);
			span.addNumber(1);
			span.addNumber(-1);
			long longest = span.longestSpan();
			long shortest = span.shortestSpan();
			std::cout << "Longest Span is: " << longest << std::endl;
			std::cout << "Shortest Span is: " << shortest << std::endl;
			if (longest != shortest)
				std::cout << "			longest and shortest ARE NOT THE SAME" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "INT_MIN INT_MAX number span:" << std::endl;
	{
		try
		{
			Span span(2);
			span.addNumber(std::numeric_limits<int>::max());
			span.addNumber(std::numeric_limits<int>::min());
			long longest = span.longestSpan();
			long shortest = span.shortestSpan();
			std::cout << "Longest Span is: " << longest << std::endl;
			std::cout << "Shortest Span is: " << shortest << std::endl;
			if (longest != shortest)
				std::cout << "			longest and shortest ARE NOT THE SAME" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}



	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Iterator batch insert from multiple source containers:" << std::endl;
	{
		Span span(100);

		std::vector<int> vec;
		vec.push_back(42);
		vec.push_back(-42);

		std::deque<int> deque;
		deque.push_back(3);
		deque.push_back(-123123);

		std::list<int> list;
		list.push_front(666);
		list.push_back(48);
		list.push_back(69420);

		std::set<int> set;
		set.insert(-321321);
		set.insert(70);

		try
		{
			span.addBatch(vec.begin(), vec.end());
			span.addBatch(deque.begin(), deque.end());
			span.addBatch(list.begin(), list.end());
			span.addBatch(set.begin(), set.end());

			span.print_numbers();

			long longest = span.longestSpan();
			long shortest = span.shortestSpan();
			std::cout << "Longest Span is: " << longest << std::endl;
			std::cout << "Shortest Span is: " << shortest << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Copy Constructor test (result must be the same as before):" << std::endl;
	{
		Span span(100);

		std::vector<int> vec;
		vec.push_back(42);
		vec.push_back(-42);

		std::deque<int> deque;
		deque.push_back(3);
		deque.push_back(-123123);

		std::list<int> list;
		list.push_front(666);
		list.push_back(48);
		list.push_back(69420);

		std::set<int> set;
		set.insert(-321321);
		set.insert(70);

		try
		{
			span.addBatch(vec.begin(), vec.end());
			span.addBatch(deque.begin(), deque.end());
			span.addBatch(list.begin(), list.end());
			span.addBatch(set.begin(), set.end());

			Span copy(span);

			copy.print_numbers();

			long longest = copy.longestSpan();
			long shortest = copy.shortestSpan();
			std::cout << "Copy Longest Span is: " << longest << std::endl;
			std::cout << "Copy Shortest Span is: " << shortest << std::endl;

			std::cout << "	Add INT_MAX to copy, test original, must be the same as previous example" << std::endl;
			copy.addNumber(std::numeric_limits<int>::max());
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Copy Assignment test (same as before, assign instead of copy):" << std::endl;
	{
		Span span(100);

		std::vector<int> vec;
		vec.push_back(42);
		vec.push_back(-42);

		std::deque<int> deque;
		deque.push_back(3);
		deque.push_back(-123123);

		std::list<int> list;
		list.push_front(666);
		list.push_back(48);
		list.push_back(69420);

		std::set<int> set;
		set.insert(-321321);
		set.insert(70);

		std::vector<int> container;
		container.push_back(342);
		container.push_back(827);

		try
		{
			span.addBatch(vec.begin(), vec.end());
			span.addBatch(deque.begin(), deque.end());
			span.addBatch(list.begin(), list.end());
			span.addBatch(set.begin(), set.end());
			span.addBatch(container);

			Span copy(2);

			copy = span;
			copy.print_numbers();

			long longest = copy.longestSpan();
			long shortest = copy.shortestSpan();
			std::cout << "Copy Longest Span is: " << longest << std::endl;
			std::cout << "Copy Shortest Span is: " << shortest << std::endl;

			std::cout << "	Add INT_MAX to copy, test original, must be the same as previous example" << std::endl;
			copy.addNumber(std::numeric_limits<int>::max());
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span capacity test (same as before, setting cap to 5):" << std::endl;
	{
		Span span(5);

		std::vector<int> vec;
		vec.push_back(42);
		vec.push_back(-42);

		std::deque<int> deque;
		deque.push_back(3);
		deque.push_back(-123123);

		std::list<int> list;
		list.push_front(666);
		list.push_back(48);
		list.push_back(69420);

		std::set<int> set;
		set.insert(-321321);
		set.insert(70);

		std::vector<int> container;
		container.push_back(342);
		container.push_back(827);

		try
		{
			span.addBatch(vec.begin(), vec.end());
			span.addBatch(deque.begin(), deque.end());
			span.addBatch(list.begin(), list.end());
			span.addBatch(set.begin(), set.end());
			span.addBatch(container);

			/*
				Iterators are more flexible (associative, sequencial), but more
				risky because there is no check that the iterators point to elements
				from the same container (only the same container type)

				Template function for containers requires more arguments for deduction,
				so we can't have only one for std::set and std::vector

				But, the compiler is able to generate machine code from the same
				template for vector, list and deque
			*/
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.print_numbers();

		long longest = span.longestSpan();
		long shortest = span.shortestSpan();
		std::cout << "Longest Span is: " << longest << std::endl;
		std::cout << "Shortest Span is: " << shortest << std::endl;
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span of 100 random numbers:" << std::endl;
	{
		try
		{
			Span span(100);

			span.addBatch(100);
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span of 1.000 random numbers:" << std::endl;
	{
		try
		{
			Span span(1000);

			span.addBatch(1000);
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span of 10.000 random numbers:" << std::endl;
	{
		try
		{
			Span span(10000);

			span.addBatch(10000);
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span of 100.000 random numbers:" << std::endl;
	{
		try
		{
			Span span(100000);

			span.addBatch(100000);
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "Span of 1.000.000 random numbers:" << std::endl;
	{
		try
		{
			Span span(1000000);

			span.addBatch(1000000);
			std::cout << "	Original longest: " << span.longestSpan() << std::endl;
			std::cout << "	Original shortest: " << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n*****************************************" << std::endl;

	return (0);
}

