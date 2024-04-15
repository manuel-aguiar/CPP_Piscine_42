/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:24:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 10:27:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();			//for test purposes
				~GradeTooHighException() throw();	//for test purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();				//for test purposes
				~GradeTooLowException() throw();	//for test purposes
				const char *what(void) const throw();
		};

		Bureaucrat(const std::string& new_name, const int new_grade) \
			throw(GradeTooHighException, GradeTooLowException);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& 		operator=(const Bureaucrat& assign);

		const std::string&	getName() const;
		int					getGrade() const;
		
		void				upgrade() throw(GradeTooHighException);
		void				downgrade() throw(GradeTooLowException);

		Bureaucrat&			operator++(void) throw(GradeTooHighException);
		Bureaucrat 			operator++(int) throw(GradeTooHighException);
		Bureaucrat&	 		operator--(void) throw(GradeTooLowException);
		Bureaucrat	 		operator--(int) throw(GradeTooLowException);


	private:
		Bureaucrat() throw(GradeTooHighException, GradeTooLowException);
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);

#endif

//TEST TO DO, put exceptions classes as private

/*
	Throw() in a function prototype means the user is not expected to get
	any exception from the execution of that function
	throw(class) means the user is expected to handle such exception

	However, specifiying throw() [noexcept c++11] and then explicitely throwing
	an exception in the function body will not result in compilation error
	Likewise, if on prototype you specify throw(A) and the function body
	~goes throw(B), no compilation error either

	These are measures to inform the end user but other exceptions could occur

	if std::string fails, for instance, and exception is thrown for bad_alloc.
	That means that, in theory, the full code that allocates memory should be
	protected in a try-catch block....

	So when specifying throw() in a prototype for an exceptions, you are telling the user
	not to expect any failure from the exception class itself

*/
