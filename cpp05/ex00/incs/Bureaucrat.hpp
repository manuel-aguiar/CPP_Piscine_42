/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:24:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 14:15:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& new_name, const int new_grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& 		operator=(const Bureaucrat& assign);

		const std::string&	getName() const;
		int					getGrade() const;

		void				upgrade();
		void				downgrade();

		Bureaucrat 			operator++(void);
		Bureaucrat& 		operator++(int);
		Bureaucrat	 		operator--(void);
		Bureaucrat& 		operator--(int);

	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);

#endif
