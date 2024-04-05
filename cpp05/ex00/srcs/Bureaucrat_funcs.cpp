/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_funcs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:44:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 14:05:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade, " << bureau.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::upgrade()
{
	grade--;
}

void	Bureaucrat::downgrade()
{
	grade++;
}

Bureaucrat	Bureaucrat::operator++(void)
{
	Bureaucrat	copy(*this);

	this->upgrade();
	return (copy);
}

Bureaucrat&	Bureaucrat::operator++(int)
{

	++(*this);
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(void)
{
	Bureaucrat	copy(*this);


	this->downgrade();
	return (copy);
}

Bureaucrat&	Bureaucrat::operator--(int)
{
	--(*this);
	return (*this);
}
