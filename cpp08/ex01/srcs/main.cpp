/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 09:25:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <limits>

void    print_int(const int& n)
{
    std::cout << n << std::endl;
}

int main(void)
{
	Span span(7);


	std::vector<int> vec;
	vec.push_back(std::numeric_limits<int>::min());
	vec.push_back(std::numeric_limits<int>::max());

	try
	{
		span.addBatch(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	span.print_numbers();

	long shortest = span.shortestSpan();
	long longest = span.longestSpan();

	std::cout << "Longest Span is: " << longest << std::endl;
	std::cout << "Shortest Span is: " << shortest << std::endl;
	return (0);
}

