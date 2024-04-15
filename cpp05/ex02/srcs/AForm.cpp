/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:40 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 12:13:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
			_name("some garbage value, i'll make it private anyways"), \
			_sign_grade(5), \
			_exec_grade(5), \
			_is_signed(false)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm Default Constructor Called" << std::endl;
	#endif
}

AForm::AForm(	const std::string&	name, \
			const int			sign_grade, \
			const int			exec_grade ) \
			throw(AFormExceptions):
			_name(name), \
			_sign_grade(sign_grade), \
			_exec_grade(exec_grade), \
			_is_signed(false)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm Parameter Constructor Called" << std::endl;
	#endif

	if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm Destructor Called" << std::endl;
	#endif
}

AForm::AForm(const AForm& copy) :
			_name(copy._name), \
			_sign_grade(copy._sign_grade), \
			_exec_grade(copy._exec_grade), \
			_is_signed(copy._is_signed)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

AForm& AForm::operator=(const AForm& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "AForm Copy Assignment Called" << std::endl;
	#endif

	if (this == &assign)
		return (*this);
	_is_signed = assign._is_signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm: " << AForm.getName() << "\n"
	<< "	sign_grade: " << AForm.getSignGrade() << "\n"
	<< "	exec_grade: " << AForm.getExecGrade() << "\n"
	<< "	is_signed? " << (AForm.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}
