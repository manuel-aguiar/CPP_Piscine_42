/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 11:46:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : \
	_name("unnamed"), \
	_grade(5)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat Default Construction Called" << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(const std::string& new_name, const int new_grade) : \
	_name(new_name), \
	_grade(new_grade)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat Parameter Construction Called" << std::endl;
	#endif

	if (new_grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (new_grade < MAX_GRADE)
		throw GradeTooHighException();
	//else
	//	grade = new_grade;
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat " << name << " Destructor Called" << std::endl;
	#endif
}

/*

	Copy constructor allows copy.name at the member initializer list
	because this->name is not initalized yet.

	However, copy assignment, this->name is already initialized and const,
	cannot be copied :)

*/

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Bureaucrat Copy Assignment Called" << std::endl;
	#endif

	if (this == &assign)
		return (*this);
	_grade = assign._grade;
	return (*this);
}


