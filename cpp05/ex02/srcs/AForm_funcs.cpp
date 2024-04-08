/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_funcs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 12:23:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Form::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

const std::string&	Form::getName() const
{
	return (_name);
}

int					Form::getSignGrade() const
{
	return (_sign_grade);
}

int					Form::getExecGrade() const
{
	return (_exec_grade);
}

int					Form::getIsSigned() const
{
	return (_is_signed);
}

