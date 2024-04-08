/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_exceptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:53 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 12:04:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
    return ("Grade: too high; range max-min: 1 - 150");
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
    return ("Grade: too low; range max-min: 1 - 150");
}
