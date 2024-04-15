/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:24:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 14:02:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();			//for test purposes
				~GradeTooHighException() throw();	//for test purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();				//for test purposes
				~GradeTooLowException() throw();	//for test purposes
				const char *what(void) const throw();
		};

		Bureaucrat(const std::string& new_name, const int new_grade) \
			throw(GradeTooHighException, GradeTooLowException);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& 		operator=(const Bureaucrat& assign);

		const std::string&	getName() const;
		int					getGrade() const;

		void				upgrade() throw(GradeTooHighException);
		void				downgrade() throw(GradeTooLowException);

		Bureaucrat&			operator++(void) throw(GradeTooHighException);
		Bureaucrat 			operator++(int) throw(GradeTooHighException);
		Bureaucrat&	 		operator--(void) throw(GradeTooLowException);
		Bureaucrat	 		operator--(int) throw(GradeTooLowException);

		void	signForm(AForm& form) throw(); //telling the end user this function doesn't throw anything
		void	executeForm(const AForm& form) throw();  //telling the end user this function doesn't throw anything


	private:
		Bureaucrat();
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);

#endif

/*
	********************************************************

	http://www.gotw.ca/publications/mill22.htm

	A Pragmatic Look at Exception Specifications

	So, throw() looks pretty useless in many cases.
	https://stackoverflow.com/questions/1037575/why-arent-exceptions-in-c-checked-by-the-compiler

	throw() is not checked by the compiler. You declare a function with throw(), and then
	explicitely throw inside the body, and the compiler accepts thhat even though
	you assigned it as not throwing anything

	It is not enforced, or checked, and the compiler must add code at runtime to
	find a try-block and unwind, by only specifiying throw

	void AStupidFunction() throw()
	{
		throw 42;
	}
	/\ valid, no problem..... makes no sintatic sense



	#include <iostream>
	#include <string>


	void some_func(void) [throw()]
	{
		std::cout << "Hello World\n";
	}

	int main(void)
	{
		some_func();
		return (0);
	}

	Throw() actually adds a bunch of code, no compiler checks....
		This code is like a try-catch that the programmer doesn't write manually, but is still there
	So assembly will show terminate calls for functions you pecify no throw (throw()),
	so isntead of taking runtime checks out, you are actually adding them in

	This function, in its body, doesn't throw anything, and still the compiler infuses such code...

	Now, if you put a throw in a base class' pure virtual function, and specify a couple of exception specifications.
	Then build a 100 Derived Classes that override it
	Now remove a throw specification in the base class. BOOM

	"
		So here’s what seems to be the best advice we as a community have learned as of today:

		Moral #1: Never write an exception specification.

		Moral #2: Except possibly an empty one, but if I were you I’d avoid even that.
	"

	Not adding checks, results in less code.
	If you are going to use them, use them where you have to...

	Then an exception is not caught or doesn't match the throw(..) classes you specified
	, compiler must call ::unexpected() which will probably lead to a terminate() :)


***********************************************************

	What problems does noexcept address?

	noexcept may be resolved at compile time, the compiler can check whether it is possible
	an exception to be thrown, if not resolve to a boolean and do add more code:


	IN REALITY I JUST CHECKED, COMPILER CAN GET RID OF THE THROW
	(If code is simple, that is)

*********************************************************

https://stackoverflow.com/questions/88573/should-i-use-an-exception-specifier-in-c/88905#88905

"
	Write code that returns common errors and throws on exceptional occasions.

		Error e = open( "bla.txt" );
		if( e == FileNotFound )
			MessageUser( "File bla.txt not found" );
		if( e == AccessDenied )
			MessageUser( "Failed to open bla.txt, because we don't have read rights ..." );
		if( e != Success )
			MessageUser( "Failed due to some other error, error code = " + itoa( e ) );

		try
		{
		std::vector<TObj> k( 1000 );
		// ...
		}
		catch( const bad_alloc& b )
		{
		MessageUser( "out of memory, exiting process" );
		throw;
		}
"

*/
