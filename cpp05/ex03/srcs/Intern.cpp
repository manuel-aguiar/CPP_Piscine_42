/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:20:30 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 14:32:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Intern Default Constructor Called" << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Intern Destructor Called" << std::endl;
	#endif
}

Intern::Intern(const Intern& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Intern Copy Constructor Called" << std::endl;
	#endif
	(void)copy;
}

Intern& Intern::operator=(const Intern& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	#endif
	(void)assign;
	return (*this);
}

const std::string	Intern::form_names[4] = \
{
	"presidential pardon",
	"robotomy request",
	"shrubbery creation",
	"cenas whatever"
};

const Intern::funcs Intern::form_factory[4] = \
{
	&Intern::new_pres,
	&Intern::new_robot,
	&Intern::new_shrub,
	&Intern::throw_unavailable
};

AForm*	Intern::new_pres(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::new_shrub(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::new_robot(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::throw_unavailable(const std::string& target)
{
	(void)target;
	throw InternUnavailableForm();
	return (0);
}

AForm*	Intern::ask_factory(const std::string& form, const std::string& target)
{
	int	i;

	i = 0;
	while (i < form_count && form != form_names[i])
		i++;
	return ((this->*form_factory[i])(target));
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target) throw()
{
	AForm*	new_form;

	try
	{
		new_form = ask_factory(form, target);
		std::cout << "Intern creates " << new_form->getName() << std::endl;
		return (new_form);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::AFormExceptions& e)
	{
		std::cerr << "Intern couldn't create form <" << form << "> because: " << e.what() << '\n';
	}
	return (0);
}

//intern exception

Intern::InternUnavailableForm::InternUnavailableForm()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "InternUnavailableForm Constructor Called" << std::endl;
	#endif
}

Intern::InternUnavailableForm::InternUnavailableForm::~InternUnavailableForm() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "InternUnavailableForm Destructor Called" << std::endl;
	#endif
}

const char *Intern::InternUnavailableForm::what() const throw()
{
    return ("form is not available");
}

