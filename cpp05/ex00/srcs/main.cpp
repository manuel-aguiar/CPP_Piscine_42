/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 09:41:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main1(void)
{
	Bureaucrat b("josé", 1);

	std::cout << b;
	try
	{
		++b;
		std::cout << "random phrase after exception is thrown by the previous line" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << b;
	}
	return (0);
}

int	main2(void)
{
	Bureaucrat b("josé", 1);

	std::cout << b;
	try
	{
		Bureaucrat c("antonio", 139);
		std::cout << c;
		++b;
		std::cout << "random phrase after exception is thrown by the previous line" << std::endl;
		/*

			This line will not be printed:
				1) exception occurs in the try block
				2) control passes to catch
				3) if an appropriate catch is found
					a) jump back in the throw() and start unwinding the stack from there, until
					the beginning of the try block
					b) execute the catch-handler function body

				4) if no appropriate catch is found
					call terminate()

			In this case, "random phrase" is not printed and "antonio"'s destructor is not called
			because no appropriate handler was found, so stack unwinding doesn't actually
			begin
		*/
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << b;
	}
	return (0);
}

int	main(void)
{
	Bureaucrat b("josé", 1);

	std::cout << b;
	try
	{
		try
		{
			Bureaucrat c("antonio", 139);
			std::cout << c;
			++b; // ops, exception
			std::cout << "random phrase after exception is thrown by the previous line" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << b;
			std::cout << "EXCEPTION 		caught in the inner loop" << std::endl;
		}
		std::cout << "catch fails, so this will not be printed wither" << std::endl;
		/*

			resolution from inenr to outter loop,
			this catch block fails, so examine the outter try
			don't execute anything in this try, go straight to the catch-handlers and try
			to find an appropriate match
		*/
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "EXCEPTION 		caught in the outter loop" << std::endl;
	}


	return (0);
}

/*

	catch(const std::exception e) ->  without the reference
	error: catching polymorphic type ‘const class std::exception’ by value [-Werror=catch-value=]
   	24 |  catch(const std::exception e)
*/

/*

	If you have multiple nested try blocks, unwinding goes from the inner to the outter try blocks


	If an exception occurs while unwinding and before the catch takes control, terminate() is called

*/
