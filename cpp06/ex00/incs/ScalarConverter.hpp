/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 13:05:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

class ScalarConverter
{
	public:
		~ScalarConverter();

		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& assign);
};



#endif
