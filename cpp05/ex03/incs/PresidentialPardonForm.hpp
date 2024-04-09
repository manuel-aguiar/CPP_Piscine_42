/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:32 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 13:50:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PRES_NAME "PresidentialPardonForm"
# define PRES_SIGN 25
# define PRES_EXEC 5

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& assign);

		const std::string&	getTarget() const;
		void				execute(const Bureaucrat& executor) const;

	private:
		const std::string	_target;
		PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& AForm);

#endif

/*

	target as part of each derived class instead of animal
	this way, one cannot change targets from one type of form to the other

	Actually, to be fair, target itself should be const, you don't sign a form
	change target, and execute

	Let's make target const

	This renders the copy constructors as pretty much useless.... :D
	As such.......

	Let's put the damn target in the AForm, as we are not going to copy anything
*/
