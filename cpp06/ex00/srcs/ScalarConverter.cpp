/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/12 09:53:17 by manuel           ###   ########.fr       */
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






static void	print_char(char c)
{
	std::cout 	<< "char: '" << c << "'" << std::endl
				<< "int: " << static_cast<int>(c) << std::endl
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}
/*
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
	CHAR,
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
int	is_char(std::string& word)
{
	if (word.length() == 1
	&& ((word[0] >= 32 && word[0] < '0')
	|| (word[0] > '9' && word[0] <= 126)))
		return (CHAR);
	return (ERROR);
}

/*
    std::cout << "char float value: " << std::numeric_limits<char>::min() << std::endl;
    std::cout << "char float value: " << std::numeric_limits<char>::max() << std::endl;
    std::cout << "int double value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int double value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Minimum float value: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum float value: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Minimum double value: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Maximum double value: " << std::numeric_limits<double>::max() << std::endl;

*/

int is_number(std::string& str)
{
	int	i;

	//basic atoi with no calculations, strtod/strtol used later
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !std::isdigit(str[i]))
		return (ERROR);
	while (str[i] && std::isdigit(str[i]))
		i++;

	//could be an int, oveflows checked later
	if (!str[i])
		return (INT);
	if (str[i] != '.')
		return (ERROR);

	//could be a float or double
	i++;
	while (str[i] && std::isdigit(str[i]))
		i++;

	//doesn't end with an 'f', it's a double
	if (!str[i])
		return (DOUBLE);
	if (str[i] == 'f' && !str[i + 1])
		return (FLOAT);

	//exponents.....
	if (str[i++] != 'e')
		return (ERROR);
	if (str[i] && str[i] != '+' && str[i] != '-')
		return (ERROR);
	i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i])
		return (ERROR);
	
	//could be float or double, lets get double and check the limits later
	return (DOUBLE);
}


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

void	print_error(void)
{
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: impossible\n"
				<< "double: impossible" << std::endl;
}

bool	too_many_args(std::string& word, std::string& literal)
{
	std::stringstream ss(literal);
	std::string dummy;

	ss >> word;
	if (ss >> dummy)
		return (true);
	return (false);
}

int		find_type(std::string& word)
{
	int	type;

	type = is_pseudo(word);
	if (!type)
		type = is_char(word);
	if (!type)
		type = is_number(word);
	return (type);
}

void	ScalarConverter::convert(std::string literal)
{
	std::string word;
	int			type;

	if (too_many_args(word, literal))
	{
		std::cout << "string literal has too many args" << std::endl;
		return ;
	}
	type = find_type(word);
	switch(type)
	{
		case ERROR:
			return (print_error());
		case CHAR:
			return (print_char(word[0]));
		case INT:
			return ;
		case FLOAT:
			return ;
		case DOUBLE:
			return ;
		case PSEUDO_NAN:
			return (print_pseudo(word, type));
		case PSEUDO_FLOAT:
			return (print_pseudo(word, type));
		case PSEUDO_DOUBLE:
			return (print_pseudo(word, type));
	}
}
