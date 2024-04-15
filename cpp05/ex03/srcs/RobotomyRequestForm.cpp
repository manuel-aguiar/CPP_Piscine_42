/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 13:19:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const bool RobotomyRequestForm::init_srand = RobotomyRequestForm::call_srand();

RobotomyRequestForm::RobotomyRequestForm() :
								AForm(ROBOT_NAME, ROBOT_SIGN, ROBOT_EXEC), \
								_target("unknown")
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
								AForm(ROBOT_NAME, ROBOT_SIGN, ROBOT_EXEC), \
								_target(target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RobotomyRequestForm Parameter Constructor Called" << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
								AForm(copy), \
								_target(copy._target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "RobotomyRequestForm Copy Assignment Called" << std::endl;
	#endif
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

/*

	execute is const, so caller cannot be chhanged internally
	can't add a variable _is_executed and change that
	so the same form can be executed multiple times

*/

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const throw(AFormExceptions)
{
	this->beExecuted(executor);
	std::cout << "Brrrrr.... ";
	if (rand() % 2)
		std::cout << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << _target << " was not robotomized successfully.... shame." << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	const AForm *dummy;

	dummy = &form;
	os << *dummy;
	os << "	target: " << form.getTarget() << std::endl;
	return (os);
}

bool RobotomyRequestForm::call_srand()
{
	std::srand(std::time(0));
	return (true);
}
