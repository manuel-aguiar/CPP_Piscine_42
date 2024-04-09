/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 11:01:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(	const std::string&	name, \
				const int			sign_grade, \
				const int			exec_grade);
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& assign);

		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		int					getIsSigned() const;

		void			beSigned(const Bureaucrat& bureau);
		void			beExecuted(const Bureaucrat& bureau) const;
		virtual void	execute(const Bureaucrat& executor) const = 0;

		class AFormExceptions : public std::exception
		{
			public:
				AFormExceptions();								//for debug purposes
				virtual ~AFormExceptions() throw();				//for debug purposes
				virtual const char *what(void) const throw() = 0;
		};

		class GradeTooHighException : public AFormExceptions
		{
			public:
				GradeTooHighException();						//for debug purposes
				~GradeTooHighException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public AFormExceptions
		{
			public:
				GradeTooLowException();							//for debug purposes
				~GradeTooLowException() throw();				//for debug purposes
				const char *what(void) const throw();
		};

		class AFormAlreadySigned : public AFormExceptions
		{
			public:
				AFormAlreadySigned();							//for debug purposes
				~AFormAlreadySigned() throw();					//for debug purposes
				const char *what(void) const throw();
		};
		class AFormNotYetSigned : public AFormExceptions
		{
			public:
				AFormNotYetSigned();							//for debug purposes
				~AFormNotYetSigned() throw();					//for debug purposes
				const char *what(void) const throw();
		};

	private:
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_is_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif


