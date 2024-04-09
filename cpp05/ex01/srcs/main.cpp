/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:14:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat b("josé", 8);
	Form f("cenas", 5, 7);
	Bureaucrat c("antonio", 1);
	std::cout << b;
	b.signForm(f);
	c.signForm(f);
	c.signForm(f);
	std::cout << b;
	return (0);
}

/*

	try-catch block is placed inside the Bureaucrat::signform(form) method, not need
	for another try-catch block outside

*/
