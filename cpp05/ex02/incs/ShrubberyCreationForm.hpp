/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:32 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 12:56:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

# define SHRUB_NAME "ShrubberyCreationForm"
# define SHRUB_SIGN 145
# define SHRUB_EXEC 137

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:

		class ShrubberyOpenFileFail : public AForm::AFormExceptions
		{
			public:
				ShrubberyOpenFileFail();						//for debug purposes
				~ShrubberyOpenFileFail() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& assign);

		const std::string&	getTarget() const;
		void				execute(const Bureaucrat& executor) const throw(AFormExceptions, ShrubberyOpenFileFail);

	private:
		const std::string	_target;
		ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& AForm);

#endif


