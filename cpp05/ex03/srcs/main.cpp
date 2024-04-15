/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 18:48:56 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << "\n\n\nMAIN 1\n" << std::endl; 

		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat boss("boss", 1);

		rrf = someRandomIntern.makeForm("tretas", "Bender");
		if (rrf)
			delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("shrubbery creation", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<ShrubberyCreationForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("robotomy request", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<RobotomyRequestForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}		
	}

	{

		std::cout << "\n\n\nMAIN 2\n" << std::endl; 

		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat boss("boss", 70);

		rrf = someRandomIntern.makeForm("tretas", "Bender");
		if (rrf)
			delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("shrubbery creation", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<ShrubberyCreationForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("robotomy request", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<RobotomyRequestForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}		
	}

	{

		std::cout << "\n\n\nMAIN 3\n" << std::endl; 

		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat boss("boss", 70);

		rrf = someRandomIntern.makeForm("tretas", "Bender");
		if (rrf)
			delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("shrubbery creation", "joaquim");
		if (rrf)
		{
			std::cout << *dynamic_cast<ShrubberyCreationForm *>(rrf);
			boss.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("robotomy request", "joaquim");
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
