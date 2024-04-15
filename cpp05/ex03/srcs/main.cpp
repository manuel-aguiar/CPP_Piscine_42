/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:09 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 14:34:36 by codespace        ###   ########.fr       */
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
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat boss("boss", 1);

	rrf = someRandomIntern.makeForm("tretas", "Bender");
	if (rrf)
		delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "joaquim");
	if (rrf)
	{
		std::cout << *rrf;
		boss.executeForm(*rrf);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	rrf = someRandomIntern.makeForm("shrubbery creation", "joaquim");
	if (rrf)
	{
		std::cout << *rrf;
		boss.executeForm(*rrf);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	rrf = someRandomIntern.makeForm("robotomy request", "joaquim");
	if (rrf)
	{
		std::cout << *rrf;
		boss.executeForm(*rrf);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	return (0);
}
