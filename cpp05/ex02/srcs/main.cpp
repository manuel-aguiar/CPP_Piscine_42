/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 18:39:34 by mmaria-d         ###   ########.fr       */
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
		ShrubberyCreationForm form("joaquim");
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

		rrf = new PresidentialPardonForm("antonio");
		if (rrf)
		{
			std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = new ShrubberyCreationForm("antonio");
		if (rrf)
		{
			std::cout << *dynamic_cast<ShrubberyCreationForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = new RobotomyRequestForm("antonio");
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

