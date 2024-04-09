/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 11:01:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(	const std::string	name, \
				const int			sign_grade, \
				const int			exec_grade);
		~Form();
		Form(const Form& copy);
		Form& operator=(const Form& assign);

		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		int					getIsSigned() const;

		void	beSigned(const Bureaucrat& bureau);

		class FormExceptions : public std::exception
		{
			public:
				FormExceptions();								//for debug purposes
				virtual ~FormExceptions() throw();				//for debug purposes
				virtual const char *what(void) const throw() = 0;
		};

		class GradeTooHighException : public FormExceptions
		{
			public:
				GradeTooHighException();						//for debug purposes
				~GradeTooHighException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public FormExceptions
		{
			public:
				GradeTooLowException();							//for debug purposes
				~GradeTooLowException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class FormAlreadySigned : public FormExceptions
		{
			public:
				FormAlreadySigned();							//for debug purposes
				~FormAlreadySigned() throw();					//for debug purposes
				const char *what(void) const throw();
		};

	private:
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_is_signed;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif


