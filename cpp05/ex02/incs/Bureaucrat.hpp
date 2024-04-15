/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:24:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 13:15:39 by codespace        ###   ########.fr       */
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



***********************************************************

	http://www.gotw.ca/publications/mill22.htm

	A Pragmatic Look at Exception Specifications

*/
