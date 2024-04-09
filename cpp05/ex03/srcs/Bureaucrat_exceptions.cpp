/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_exceptions.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:57:28 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 12:04:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Grade too high
Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat GradeTooHighException Constructor Called" << std::endl;
	#endif
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat GradeTooHighException Destructor Called" << std::endl;
	#endif
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat: Grade: too high; range max-min: 1 - 150");
}


// Grade too low
Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat GradeTooLowException Constructor Called" << std::endl;
	#endif
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat GradeTooLowException Destructor Called" << std::endl;
	#endif
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: Grade: too low; range max-min: 1 - 150");
}
