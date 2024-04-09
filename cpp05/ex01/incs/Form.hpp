/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 12:04:42 by codespace        ###   ########.fr       */
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
		Form(	const std::string&	name, \
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
				FormExceptions();								//for debug purposes
				virtual ~FormExceptions() throw();				//for debug purposes
				virtual const char *what(void) const throw() = 0;
		};

		class GradeTooHighException : public FormExceptions
		{
			public:
				GradeTooHighException();						//for debug purposes
				~GradeTooHighException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public FormExceptions
		{
			public:
				GradeTooLowException();							//for debug purposes
				~GradeTooLowException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class FormAlreadySigned : public FormExceptions
		{
			public:
				FormAlreadySigned();							//for debug purposes
				~FormAlreadySigned() throw();					//for debug purposes
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

/*

	we could actually make the derived exceptions to be private but the subject
	demands it to be public for a try catch :(
	Interesting idea anyways

*/

/*

	"My class has a nested class with a [pure] virtual function. Does the outter class,
	with no virtual functions, have a vtable?"

	Asssembly!!! (keep in mind, always compiler and ABI dependent, my boys and gals)

	https://godbolt.org/#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAMzwBtMA7AQwFtMQByARg9KtQYEAysib0QXACx8BBAKoBnTAAUAHpwAMvAFYTStJg1DIApACYAQuYukl9ZATwDKjdAGFUtAK4sGIM6SuADJ4DJgAcj4ARpjEIADMAQAOqAqETgwe3r56KWmOAiFhkSwxcVy2mPYFDEIETMQEWT5%2BAXaYDhl1DQRFEdGxCW31jc05FQojvaH9pYNcAJS2qF7EyOwc5vGhyN5YANQm8W5hAO5H2CYaAIJbO3uYh8dOk8SYrBdXtze7TAoK%2BxWBAIsS%2BJgA7FYbvsYfskl4orQ8MgQF9Yej9r9/vtQmFiGiMTCIVDroTCfDEcjUdCybSAG54RpeMT7AB%2BuNiEAWh0hEIAIkcSbT6YyCMzaPs6ag8OhMYw/lyeRZJugQCggU83Ec3IczGZ1swFOYzJrtfsVWrXLRBfybTTCbb4iSCYSsQCsMQ8HTMLKQHCEUjkDiGHiXRjiWHaRTA9TScLCayPV6fYqI%2BCBU7I/HJdLZQaFdziRb1V4CKbjrr9fKjXryzri1abem7XGHc3MzcszCpTLMdKFAWiwRVSWy9qzca0HgBzWTeOKw2GOhrZn28612CbqEyywmKEID30Aswbz7YDSyDiOeCC30UCAHRTmdc2%2BwoGXtUcq%2BhV8w0KP6sXw7Vtrw/EAk29WUPV/fYPQAw0gPXPkOCWWhOAAVl4PwOC0UhUE4LVLGsc0VjWR4th4UgCE0FClgAaxASR0PvJiAE5wXBDQuCkVjJDMdD4n0ThJCwmi8M4XgFBADQqJopY4FgJA0BYJI6FichKGU1T6DiYAuESPg6EvKSICiMSolCBoAE9OEoizmGIKyAHkom0DpqO4XhlLYQQnIYWgbJw3gsCiLxgDcMRaCkzzSCwXcjHEILYsZdzk2i3DMFUDpSw2SjtyqMSkSiYhrI8LAxIIT0WFs3hvWIKJUkwPlMHi4AkSMOS%2BAMYAFAANTwTBTicpJGBqmRBBEMR2Ckcb5CUNQxN0CoDA60wiMsfQ8CiKTICWVAkhqaLeFQOrPSwHauUqaoMhcJcxj8CpghmEoylyVJ0gEe63vyDI%2Bhe%2BYrtSgRulGTwWj0dpOmBqY/oGcpbCmL6Jhh564YkJYFFI9Z0aEjhMNIbDcPwjh9lUAAOAA2ABaCnJH2YBkCDfT7xNCBcEIEhdXiRZeA8rQFnokB0Mke9hY0PVWLJsn0I0dDwUkcFcZEgmxOJyTpNkoKBdxsxRKStXNf5pY6rSZxJCAA

	#include <new>
	#include <iostream>

	class outter
	{
		public:
			class inner
			{
				public:
					virtual ~inner() {};
					virtual void cenas() {std::cout << "cenas" << std::endl;};
			};

			class derived : public inner
			{
				public:
					~derived() {};
					void cenas() {std::cout << "cenas" << std::endl;};
			};

			void coisas(){std::cout << "coisas" << std::endl;};
	};

	int main(void)
	{
		outter out;
		out.coisas();
		outter::inner in;
		in.cenas();
		outter::derived der;
		der.cenas();
	}

	Nop, outter does not have a vtable :0. However, expectedly, outter::inner and outter::derived do :)

	vtable for outter::derived:
			.quad   0
			.quad   typeinfo for outter::derived
			.quad   outter::derived::~derived() [complete object destructor]
			.quad   outter::derived::~derived() [deleting destructor]
			.quad   outter::derived::cenas()
	vtable for outter::inner:
			.quad   0
			.quad   typeinfo for outter::inner
			.quad   outter::inner::~inner() [complete object destructor]
			.quad   outter::inner::~inner() [deleting destructor]
			.quad   outter::inner::cenas()
	typeinfo for outter::derived:
			.quad   vtable for __cxxabiv1::__si_class_type_info+16
			.quad   typeinfo name for outter::derived
			.quad   typeinfo for outter::inner
	typeinfo name for outter::derived:
			.string "N6outter7derivedE"
	typeinfo for outter::inner:
			.quad   vtable for __cxxabiv1::__class_type_info+16
			.quad   typeinfo name for outter::inner
	typeinfo name for outter::inner:
			.string "N6outter5innerE"

	If you change main to:
	"
		int main(void)
		{
			outter out;
			out.coisas();
			outter::inner in;
			in.cenas();
			outter::inner *der;
			der = new outter::derived;
			der->cenas();
			delete der;
		}
	"
	same result :)
*/
