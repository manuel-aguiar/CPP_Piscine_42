/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:59:28 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 12:00:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	tests(int n) throw(std::bad_alloc)
{
	Base *ptr;

	for (int i = 0; i < n; i++)
	{
		ptr = generate();
		std::cout << "Ptr test: ";
		identify(ptr);
		std::cout << "Ref test: ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
}

int main(void)
{
	try
	{
		tests(10);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
