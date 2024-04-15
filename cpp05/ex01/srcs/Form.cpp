/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:40 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 18:25:00 by mmaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
			_name("some garbage value, i'll make it private anyways"), \
			_sign_grade(5), \
			_exec_grade(5), \
			_is_signed(false)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form Default Constructor Called" << std::endl;
	#endif
}

Form::Form(	const std::string&	name, \
			const int			sign_grade, \
			const int			exec_grade ) \
			throw(FormExceptions) :
			_name(name), \
			_sign_grade(sign_grade), \
			_exec_grade(exec_grade), \
			_is_signed(false)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form Parameter Constructor Called" << std::endl;
	#endif

	if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw GradeTooHighException();
}

Form::~Form()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form Destructor Called" << std::endl;
	#endif
}

Form::Form(const Form& copy) :
			_name(copy._name), \
			_sign_grade(copy._sign_grade), \
			_exec_grade(copy._exec_grade), \
			_is_signed(copy._is_signed)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

Form& Form::operator=(const Form& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Form Copy Assignment Called" << std::endl;
	#endif

	if (this == &assign)
		return (*this);
	_is_signed = assign._is_signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << "\n"
	<< "	sign_grade: " << form.getSignGrade() << "\n"
	<< "	exec_grade: " << form.getExecGrade() << "\n"
	<< "	is_signed? " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}
