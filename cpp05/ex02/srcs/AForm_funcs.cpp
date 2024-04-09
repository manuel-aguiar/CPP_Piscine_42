/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_funcs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:13:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	AForm::beSigned(const Bureaucrat& bureau)
{
	if (_is_signed)
		throw AForm::AFormAlreadySigned();
	if (bureau.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

const std::string&	AForm::getName() const
{
	return (_name);
}

int					AForm::getSignGrade() const
{
	return (_sign_grade);
}

int					AForm::getExecGrade() const
{
	return (_exec_grade);
}

int					AForm::getIsSigned() const
{
	return (_is_signed);
}

