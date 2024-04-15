/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 18:17:13 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*

	If you have multiple nested try blocks, unwinding goes from the inner to the outter try blocks


	If an exception occurs while unwinding and before the catch takes control, terminate() is called

*/

int	main(void)
{
	{
		std::cout << "MAIN 1\n" << std::endl; 

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
			catch(const Bureaucrat::GradeTooHighException& e)	//changing this to the one we expect to get
			{
				std::cerr << e.what() << std::endl;
				std::cout << b;
				std::cout << "EXCEPTION 		caught in the inner loop" << std::endl;

				throw ;		// let's scale it upwards and see what happens :)
							// going to throw this same expection, until it find a try-catch block that
							// can handle it ( if not, terminate() )

			}
			std::cout << "catch fails, so this will not be printed wither" << std::endl;
			/*
				This output will not show up

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

			// exception was caught again in the outter try-block :)
		}

		std::cout << "exiting program" << std::endl;
	}

	std::cout << "\n\n\nMAIN 2\n" << std::endl; 

	{
		Bureaucrat b("josé", 1);

		std::cout << b;
		try
		{
			++b;
			std::cout << "random phrase after exception is thrown by the previous line" << std::endl;
			/*
				won't print, throw() is called when ++b; control passes to the try-block,
				which passes to the catch-block

			*/
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << b;

			/*

				Throw passes execution to the try-block, which passes to the catch-block

				So, technically, the function that called "throw()" is not "exited" but
				the program counter and stack pointer go to some other point in the code

				Only after the appropriate catch-handler is found will stack unwinding start.

				In this case, bureaucrat's grade was unsuccessfully increased.

			*/
		}
	}

	std::cout << "\n\n\nMAIN 3\n" << std::endl; 

	{
		Bureaucrat *b;

		try
		{
			//throw; 	// <- throw will try to find an outter try-catch block (there is none), stack unwinding and call terminate
						// "terminate called without an active exception"
						// you either throw an exception class from outside the catch-block, or throw; within the catch block
						// which will try to find another handler outside


			b = new Bureaucrat("josé", 1);
			++(*b);
			std::cout << "random phrase after exception is thrown by the previous line" << std::endl;

		}
		catch(const std::bad_alloc& e)
		{
			std::cerr << e.what() << std::endl;
			// throw;	// tries to find an outter try-catch block that can handle the bad_alloc exception (there is none)
						//

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			delete b;
			//throw;	// tries to find an outter try-catch block that can handle the exception (there is none)
						// terminate called after throwing an instance of 'Bureaucrat::GradeTooHighException'
						// catch will "catch" any derived Class from std::exception
						// generic handling, one could decouple the exceptions we expect to catch
						// and make it more sppecific and clear to someone else reading your code

						// bad_alloc itself is Derived from std::exception, but we made it specific to catch that one
						// in this particular case the handling is actually different :D, but we could just
						// want to make it specific
		}
	}

	std::cout << "\n\n\nMAIN 4\n" << std::endl; 
	/*

	using "new" inside a try block

	try block, or anything within {} sets a scope for any variables inside
	so, if you are calling new, the variable must come from the outter scope or else
	the pointer is lost, FOREVER :)


	*/


	/*

		Bureaucrat Parameter Construction Called
		josé, bureaucrat grade, 1
		Bureaucrat Parameter Construction Called
		antonio, bureaucrat grade, 139
		GradeTooHighException Constructor Called		<- Exception Construtor is called before stack_unwinding
		Bureaucrat antonio Destructor Called			<- Only afterwards, unwinding starts
		Grade: too high; range max-min: 1 - 150
		josé, bureaucrat grade, 1
		GradeTooHighException Destructor Called
		Bureaucrat josé Destructor Called

	*/
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
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << b;
		}
	}

	std::cout << "\n\n\nMAIN 5\n" << std::endl; 

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

			// exception isn't caught :0 because we were specific about the one we wanted
		}
		std::cout << "catch fails, so this will not be printed wither" << std::endl;
		/*
			This output will not show up

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

		std::cout << "exiting program" << std::endl;
	}
	return (0);
}


/*
	try without catch or catch without try, doesn't allow compilation
*/


/*

	catch(const std::exception e) ->  without the reference
	error: catching polymorphic type ‘const class std::exception’ by value [-Werror=catch-value=]
   	24 |  catch(const std::exception e)
*/

