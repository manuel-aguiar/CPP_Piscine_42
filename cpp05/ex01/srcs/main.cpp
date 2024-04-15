/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 18:29:40 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	std::cout << "\n\n\nMAIN 1\n" << std::endl; 

	{
		Bureaucrat b("josé", 8);
		Form f("cenas", 5, 7);
		Bureaucrat c("antonio", 1);
		std::cout << b;
		b.signForm(f);
		c.signForm(f);
		c.signForm(f);
		std::cout << b;		
	}

	

	{
		std::cout << "\n\n\nMAIN 2\n" << std::endl; 
		Form b("tretas", 10, 10);
		Bureaucrat juau("hey", 12);
		try
		{
			b.beSigned(juau);
		}
		catch(const Form::FormExceptions& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\n\nMAIN 3\n" << std::endl; 
		try
		{
			Form b("tretas", 0, 10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\n\nMAIN 4\n" << std::endl; 
		try
		{
			Form b("tretas", 1, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return (0);
}


/*

	try-catch block is placed inside the Bureaucrat::signform(form) method, not need
	for another try-catch block outside

*/

/*
	make debug

	Bureaucrat josé Parameter Construction Called
	Form Parameter Constructor Called
	Bureaucrat antonio Parameter Construction Called
	josé, bureaucrat grade, 8
	Form FormExceptions Constructor Called
	Form GradeTooLowException Constructor Called
	josé couldn't sign cenas because Form: Grade too low
	Form GradeTooLowException Destructor Called
	Form FormExceptions Destructor Called
	antonio signed cenas
	Form FormExceptions Constructor Called
	Form FormAlreadySigned Constructor Called
	antonio couldn't sign cenas because Form: form is already signed
	Form FormAlreadySigned Destructor Called
	Form FormExceptions Destructor Called
	josé, bureaucrat grade, 8
	Bureaucrat antonio Destructor Called
	Form Destructor Called
	Bureaucrat josé Destructor Called

	Exceptions is initialized with the throw keyword,
	as expected, order of construction of exception classes
	is the same as any other derived class :)



*/

/*

	Interesting note:
		Our Form class has a class itself that is abstract:
		Form::FormExceptions

		BUT: we can still instantiate our Form without a problem

*/
