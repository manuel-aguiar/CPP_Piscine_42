/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:07 by codespace         #+#    #+#             */
/*   Updated: 2024/04/12 09:15:50 by manuel           ###   ########.fr       */
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



#endif
