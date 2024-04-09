/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_funcs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:44:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 09:53:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*

	"throw" inside a catch block will try to find an outter try-catch block
	to scale the problem to outside the function.
		side note: throw without an active exception

	In the context of the exercise, both with/without throw can make sense
	i opted for not "throwing" after getting the exception at the bureaucrat
	at the signing level and let the program run as usual, catching
	future exceptions that might occur from non signing

	However, "throwing" upwards may make sense if the rest of the program
	depends on signForm

	As we are just testing and have no general guidelines apart from printing
	messages regarding success/failure, i don't throw and my main is
	smaller :D

*/

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const Form::FormExceptions& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() <<" because " << e.what() << std::endl;
		//throw; // <- "throw" here will try to find an outter try-catch block
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " caught a non-Form exception :0, we need to handle that!!!" << std::endl;
		// throw ;
		/*
			Bureaucrat doesn't know what to do here unless it is a Form issue :(
			Either we handle that or maybe send a throw for an outter try-catch block to handle that
			In the spirit of the exercise, we won't throw anything :D
		*/
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
