/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_funcs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:44:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 08:52:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade, " << bureau.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::upgrade() throw(GradeTooHighException)
{
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downgrade() throw(GradeTooLowException)
{
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	_grade++;
}

/*
	pre-increment
*/

Bureaucrat&	Bureaucrat::operator++(void) throw(GradeTooHighException)
{
	this->upgrade();
	return (*this);
}

/*
	Post increment
*/

Bureaucrat	Bureaucrat::operator++(int) throw(GradeTooHighException)
{
	Bureaucrat	copy(*this);

	++(*this);
	return (copy);
}

/*
	pre-decrement
*/

Bureaucrat&	Bureaucrat::operator--(void) throw(GradeTooLowException)
{
	this->downgrade();
	return (*this);
}

/*
	post-decrement
*/

Bureaucrat	Bureaucrat::operator--(int) throw(GradeTooLowException)
{
	Bureaucrat	copy(*this);

	--(*this);
	return (copy);
}
