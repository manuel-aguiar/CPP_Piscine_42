/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:20:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 15:40:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

# define INTERN_HPP

#include <string>
#include <new>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& assign);

		void	makeForm(const std::string& form_name, const std::string& target);

	private:
		typedef					AForm* (Intern::*funcs)(const std::string& target);
		PresidentialPardonForm*	new_pres(const std::string& target);
		ShrubberyCreationForm*	new_shrub(const std::string& target);
		RobotomyRequestForm*	new_robot(const std::string& target);
		AForm*					throw_dummy(const std::string& target);
		static const 		funcs factory[4] =
		{
			&new_pres,
			&new_shrub,
			&new_robot,
			&throw_dummy
		}
};

/*

	This is called the factory method in C++. Constructors do not return anything
	and cannot be assigned to function pointers.
	Additionally, since makeForm must return a pointer, we know in fact we will be
	calling <new>

	The question is to call the new against the correct derived class

*/

#endif
