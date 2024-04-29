/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/29 15:46:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void    print_int(const int& n)
{
    std::cout << n << std::endl;
}

/*
int main()
{
    std::set<int> set;

    set.insert(1);
    set.insert(-3);

    std::for_each(set.begin(), set.end(), print_int);
    std::cout << std::endl;
    std::vector<int> numbers;
	for (int i = 0; i < 5; ++i)
		numbers.push_back(i + 1);

    set.insert(numbers.begin(), numbers.end());

    std::for_each(set.begin(), set.end(), print_int);

    return 0;
}
*/

int main(void)
{
	Span span(1000000);

	span.addNumber(1);
	span.addNumber(4);
	span.addBatch(3, 50000);

	std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
	std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
	return (0);
}

