/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 14:48:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span span(100000);

	span.addBatch(100000);
	//span.print_numbers();
	std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
	std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
	return (0);
}
