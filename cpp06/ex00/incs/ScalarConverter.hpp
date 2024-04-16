/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 11:44:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <iomanip>
# include <limits>
# include <cerrno>
# include <cstdlib>

class ScalarConverter
{
	public:
		static void convert(std::string literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& assign);
};

enum
{
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	PSEUDO_NAN,
};


/*
	This is probably the worst code i have ever written i'm my very long....
	months experience :D
*/

#endif
