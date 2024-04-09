/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 14:52:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	RobotomyRequestForm form("joaquim");
	Bureaucrat juau("juau", 1);

	juau.signForm(form);
	juau.signForm(form);
	juau.executeForm(form);
	juau.executeForm(form);
	juau.executeForm(form);
	juau.executeForm(form);
	juau.executeForm(form);

	//form.execute(juau);
	return (0);
}

int	main1(void)
{
	PresidentialPardonForm form("joaquim");
	std::cout << form;
	PresidentialPardonForm outro("antonio");
	std::cout << outro;
	outro = form;
	std::cout << outro;

	return (0);
}

/*

	try-catch block is placed inside the Bureaucrat::signform(form) method, not need
	for another try-catch block outside

*/

/*
	make debug

	Bureaucrat josé Parameter Construction Called
	Form Parameter Constructor Called
	Bureaucrat antonio Parameter Construction Called
	josé, bureaucrat grade, 8
	Form FormExceptions Constructor Called
	Form GradeTooLowException Constructor Called
	josé couldn't sign cenas because Form: Grade too low
	Form GradeTooLowException Destructor Called
	Form FormExceptions Destructor Called
	antonio signed cenas
	Form FormExceptions Constructor Called
	Form FormAlreadySigned Constructor Called
	antonio couldn't sign cenas because Form: form is already signed
	Form FormAlreadySigned Destructor Called
	Form FormExceptions Destructor Called
	josé, bureaucrat grade, 8
	Bureaucrat antonio Destructor Called
	Form Destructor Called
	Bureaucrat josé Destructor Called

	Exceptions is initialized with the throw keyword,
	as expected, order of construction of exception classes
	is the same as any other derived class :)



*/
