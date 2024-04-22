/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/22 10:33:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span span(1000000);

	span.addNumber(1);
	span.addBatch(100000);

	std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
	std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
	return (0);
}
