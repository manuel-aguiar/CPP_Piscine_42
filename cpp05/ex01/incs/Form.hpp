/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:55:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(	const std::string	name, \
				const int			sign_grade, \
				const int			exec_grade);
		~Form();
		Form(const Form& copy);
		Form& operator=(const Form& assign);

		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		int					getIsSigned() const;

		void	beSigned(const Bureaucrat& bureau);

		class FormExceptions : public std::exception
		{
			public:
				FormExceptions();								//for test purposes
				virtual ~FormExceptions() throw();				//for test purposes
				virtual const char *what(void) const throw() = 0;
		};

		class GradeTooHighException : public FormExceptions
		{
			public:
				GradeTooHighException();						//for test purposes
				~GradeTooHighException() throw();				//for test purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public FormExceptions
		{
			public:
				GradeTooLowException();							//for test purposes
				~GradeTooLowException() throw();				//for test purposes
				const char *what(void) const throw();
		};

		class FormAlreadySigned : public FormExceptions
		{
			public:
				FormAlreadySigned();							//for test purposes
				~FormAlreadySigned() throw();					//for test purposes
				const char *what(void) const throw();
		};

	private:
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_is_signed;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif


/*

	Exceptions can be generic or more specific
	To make it more interesting, i want the bureaucrat to just be worried about
	specific Form Exceptions
		In this case, Form is initialized and no more containers/templates
		are initialized, so nothing will "throw" any exception at us, except
		the form itself
		so, Bureaucrat, instead of  catch (std::exception), will
		try to catch (Form::FormExceptions)

	Form exceptions inherit from the main handler which makes its destructor virtual
	as well as the what function (pure virtual, such that the compiler, won't let us
	instantiate and throw an exception that does not override the What() function :) )

	In general, maybe sticking to catch (std::exception) may be agood idea because
	you will have containers that may throw something at you and you need to handle it

	However, the handling may be different from a runtime problem regarding inputs
	from, say, a failure to allocate memory or save a file

	The bureaucrat, to be sure, can have a double catch:
		catch Form::Exceptions
		{

		}
		catch std::exceptions
		{
			implement code to manage these, but hey, still not granular enough, depending on the case
		}

	Order of catching matters, start with the specifics and then go to the generics
*/
