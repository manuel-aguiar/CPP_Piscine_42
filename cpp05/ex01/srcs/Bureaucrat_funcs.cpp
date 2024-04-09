/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_funcs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:44:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:15:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() <<" because " << e.what() << std::endl;
	}
	catch(const Form::FormAlreadySigned& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() <<" because " << e.what() << std::endl;
	}
}

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

void	Bureaucrat::upgrade()
{
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downgrade()
{
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	_grade++;
}

/*
	pre-increment
*/

Bureaucrat&	Bureaucrat::operator++(void)
{
	this->upgrade();
	return (*this);
}

/*
	Post increment
*/

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	copy(*this);

	++(*this);
	return (copy);
}

/*
	pre-decrement
*/

Bureaucrat&	Bureaucrat::operator--(void)
{
	this->downgrade();
	return (*this);
}

/*
	post-decrement
*/

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	copy(*this);

	--(*this);
	return (copy);
}
