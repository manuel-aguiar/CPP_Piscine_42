/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_exceptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:53 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 11:33:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// generic
Form::FormExceptions::FormExceptions()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form FormExceptions Constructor Called" << std::endl;
	#endif
}

Form::FormExceptions::~FormExceptions() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form FormExceptions Destructor Called" << std::endl;
	#endif
		//throw AForm::GradeTooHighException();
	/*

	With this throw, even on a double try-catch, the program will call terminate
	since by the standard, destructors throwing wile resolving a previous
	exception will always call terminate

	throw() in the destructor signature does not prevent to "throw" in the
	destructor body

	All of this is bad practice, we are just experimenting :)

	int	main(void)
{
	Bureaucrat b("josé", 8);
	AForm f("cenas", 5, 7);
	Bureaucrat c("antonio", 1);
	try
	{
		try
		{
			std::cout << b;
			b.signAForm(f);
			c.signAForm(f);
			c.signAForm(f);
			std::cout << b;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}




	return (0);
	}
	*/
}

//grade too high
Form::GradeTooHighException::GradeTooHighException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form GradeTooHighException Constructor Called" << std::endl;
	#endif
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form GradeTooHighException Destructor Called" << std::endl;
	#endif
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade too high");
}


// Grade too low
Form::GradeTooLowException::GradeTooLowException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form GradeTooLowException Constructor Called" << std::endl;
	#endif
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form GradeTooLowException Destructor Called" << std::endl;
	#endif
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade too low");
}

//form already signed
Form::FormAlreadySigned::FormAlreadySigned()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form FormAlreadySigned Constructor Called" << std::endl;
	#endif
}

Form::FormAlreadySigned::~FormAlreadySigned() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form FormAlreadySigned Destructor Called" << std::endl;
	#endif
}

const char *Form::FormAlreadySigned::what() const throw()
{
    return ("Form: form is already signed");
}
