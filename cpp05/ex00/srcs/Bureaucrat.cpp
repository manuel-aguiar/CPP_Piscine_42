/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:29:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 14:15:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& new_name, const int new_grade) : \
	name(new_name), \
	grade(new_grade)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat Parameter Construction Called" << std::endl;
	#endif
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << "Bureaucrat Destructor Called" << std::endl;
	#endif
}

/*

	Copy constructor allows copy.name at the member initializer list
	because this->name is not initalized yet.

	However, copy assignment, this->name is already initialized and const,
	cannot be copied :)

*/

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& assign)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat Copy Assignment Called" << std::endl;
	#endif
	if (this == &assign)
		return (*this);
	grade = assign.grade;
	return (*this);
}

