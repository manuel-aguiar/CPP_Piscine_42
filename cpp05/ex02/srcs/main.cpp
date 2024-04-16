/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 08:57:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main(void)
{

	std::cout << "\n\n\nMAIN 1\n" << std::endl;

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
	}


	std::cout << "\n\n\nMAIN 2\n" << std::endl;


	{
		PresidentialPardonForm form("joaquim");
		std::cout << form;
		PresidentialPardonForm outro("antonio");
		std::cout << outro;
		outro = form;
		std::cout << outro;
	}

	std::cout << "\n\n\nMAIN 3\n" << std::endl;

	{
		AForm* rrf;
		Bureaucrat boss("boss", 1);

		rrf = new (std::nothrow) PresidentialPardonForm("antonio");
		if (rrf)
		{
			std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = new (std::nothrow) ShrubberyCreationForm("antonio");
		if (rrf)
		{
			std::cout << *dynamic_cast<ShrubberyCreationForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = new (std::nothrow) RobotomyRequestForm("antonio");
		if (rrf)
		{
			std::cout << *dynamic_cast<RobotomyRequestForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}
	return (0);
}

/*

	try-catch block is placed inside the Bureaucrat::signform(form) method, not need
	for another try-catch block outside

*/

