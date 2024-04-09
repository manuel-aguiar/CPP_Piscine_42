/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 13:50:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
								AForm(PRES_NAME, PRES_SIGN, PRES_EXEC), \
								_target("unknown")
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
								AForm(PRES_NAME, PRES_SIGN, PRES_EXEC), \
								_target(target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "PresidentialPardonForm Parameter Constructor Called" << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
								AForm(copy), \
								_target(copy._target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "PresidentialPardonForm Copy Assignment Called" << std::endl;
	#endif
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	return (*this);
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (_target);
}

/*

	execute is const, so caller cannot be chhanged internally
	can't add a variable _is_executed and change that
	so the same form can be executed multiple times

*/

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->beExecuted(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."  << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	const AForm *dummy;

	dummy = &form;
	os << *dummy;
	os << "	target: " << form.getTarget() << std::endl;
	return (os);
}
