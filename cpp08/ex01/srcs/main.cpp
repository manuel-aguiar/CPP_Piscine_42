/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 11:25:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span span(10);

	span.addNumber(-1);
	span.addNumber(2);
	span.addNumber(10);
	span.addNumber(4);
	span.addNumber(6);
	span.print_numbers();
	std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
	std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
	return (0);
}
