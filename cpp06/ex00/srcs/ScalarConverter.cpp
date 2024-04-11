/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 15:24:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Constructor called" << std::endl;
	#endif
}

ScalarConverter::~ScalarConverter()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Destructor called" << std::endl;
	#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ScalarConverter Copy Assignment called" << std::endl;
	#endif
	(void)assign;
	return (*this);
}




bool	too_many_args(std::stringstream& ss)
{
	std::string dummy;

	if (ss >> dummy)
		return (true);
	return (false);
}
/*
static void	print(char c)
{
	std::cout 	<< "char: '" << c << "'" << std::endl
				<< "int: " << static_cast<int>(c) << std::endl
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void	print(int i)
{
	std::cout << "int print called" << std::endl;
	//char
	std::cout << "char: ";
	if (i > 31 && i <= 127)
		std::cout << "'" << static_cast<char>(i) << "'";
	else
		std::cout << "Non displayable";

	//int
	std::cout << "\nint: " << i

	//float
	<< "\nfloat: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f'

	//double
	<< "\ndouble: " << std::fixed << std::setprecision(1) << static_cast<double>(i)
	<< std::endl;
}
*/
/*
static void	print(float f)
{

}


static void	print(double d)
{

}
*/

enum
{
	ERROR,
	CHAT,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	PSEUDO_NAN,
};

int	is_pseudo(const std::string& str)
{
	if (str == "+inf" || str == "-inf")
		return (PSEUDO_DOUBLE);
	if (str == "+inff" || str == "-inff")
		return (PSEUDO_FLOAT);
	if (str == "nan" || str == "nanf")
		return (PSEUDO_NAN);
	return (0);
}
/*
int	valid_float(const std::string& str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	i
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (!str[i])
		return (INT);
	if (str[i] != )
}

bool	valid_int(const std::string& str, int& place_int)
{
	int i;
	int res;
	int neg;

	i = 0;
	if (!str[i] || !(str[i] == '-' || str[i] == '+'))
		return (false);
	neg = str[i] == '-'
	i++;
	if (!std::isdigit(str[i]))
		return (false);

}
*/
void	print_pseudo(std::string& word, int type)
{
	std::string sfloat;
	std::string sdouble;

	switch (type)
	{
		case PSEUDO_FLOAT:
		{
			sfloat = word;
			sdouble = word.substr(0, 4);
			break ;
		}
		case PSEUDO_DOUBLE:
		{
			sfloat = word + "f";
			sdouble = word;
			break ;
		}
		case PSEUDO_NAN:
		{
			sfloat = "nanf";
			sdouble = "nan";
		}
	}
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: " << sfloat << '\n'
				<< "double: " << sdouble << std::endl;
}

void	print_nan(void)
{
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: nanf\n"
				<< "double: nanf" << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	std::stringstream ss(literal);
	std::string word;

	ss >> word;
	if (too_many_args(ss))
	{
		std::cout << "too many args" << std::endl;
		return ;
	}
	int pseudo = is_pseudo(word);
	if (pseudo)
		return (print_pseudo(word, pseudo));
}
