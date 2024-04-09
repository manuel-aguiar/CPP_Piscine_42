/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_exceptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:53 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 11:16:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// generic
AForm::AFormExceptions::AFormExceptions()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormExceptions Constructor Called" << std::endl;
	#endif
}

AForm::AFormExceptions::~AFormExceptions() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormExceptions Destructor Called" << std::endl;
	#endif

}

//grade too high
AForm::GradeTooHighException::GradeTooHighException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm GradeTooHighException Constructor Called" << std::endl;
	#endif
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm GradeTooHighException Destructor Called" << std::endl;
	#endif
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}


// Grade too low
AForm::GradeTooLowException::GradeTooLowException()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm GradeTooLowException Constructor Called" << std::endl;
	#endif
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm GradeTooLowException Destructor Called" << std::endl;
	#endif
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

//AForm already signed
AForm::AFormAlreadySigned::AFormAlreadySigned()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormAlreadySigned Constructor Called" << std::endl;
	#endif
}

AForm::AFormAlreadySigned::~AFormAlreadySigned() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormAlreadySigned Destructor Called" << std::endl;
	#endif
}

const char *AForm::AFormAlreadySigned::what() const throw()
{
    return ("is already signed");
}

//AForm not yet signed
AForm::AFormNotYetSigned::AFormNotYetSigned()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormNotYetSigned Constructor Called" << std::endl;
	#endif
}

AForm::AFormNotYetSigned::~AFormNotYetSigned() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm AFormNotYetSigned Destructor Called" << std::endl;
	#endif
}

const char *AForm::AFormNotYetSigned::what() const throw()
{
    return ("is not yet signed");
}
