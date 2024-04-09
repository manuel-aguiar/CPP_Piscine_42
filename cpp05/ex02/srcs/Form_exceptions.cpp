/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_exceptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:53 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:58:05 by codespace        ###   ########.fr       */
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
