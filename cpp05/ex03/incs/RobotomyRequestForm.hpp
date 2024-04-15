/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:32 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 13:19:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <cstdlib>
# include <ctime>

# define ROBOT_NAME "RobotomyRequestForm"
# define ROBOT_SIGN 72
# define ROBOT_EXEC 45

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& assign);

		const std::string&	getTarget() const;
		void				execute(const Bureaucrat& executor) const throw(AFormExceptions);

		static bool	call_srand();

	private:
		static const bool 	init_srand;
		const std::string	_target;
		RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& AForm);

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
