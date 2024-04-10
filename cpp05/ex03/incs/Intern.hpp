/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:20:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/10 11:56:18 by codespace        ###   ########.fr       */
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

# define FORM_COUNT 3

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& assign);

		AForm* 	makeForm(const std::string& form, const std::string& target);

		class InternUnavailableForm : public AForm::AFormExceptions
		{
			public:
				InternUnavailableForm();						//for debug purposes
				~InternUnavailableForm() throw();				//for debug purposes
				const char *what(void) const throw();
		};

	private:
		typedef						AForm* (Intern::*funcs)(const std::string& target);
		AForm*						new_pres(const std::string& target);
		AForm*						new_shrub(const std::string& target);
		AForm*						new_robot(const std::string& target);
		AForm*						throw_dummy(const std::string& target);
		AForm*						ask_factory(const std::string& form, const std::string& target);
		static const std::string	form_names[4];
		static const funcs			form_factory[4];
		static const int			form_count = FORM_COUNT;
};


/*

	This is called the factory method in C++. Constructors do not return anything
	and cannot be assigned to function pointers.
	Additionally, since makeForm must return a pointer, we know in fact we will be
	calling <new>

	The question is to call the new against the correct derived class

*/

#endif
