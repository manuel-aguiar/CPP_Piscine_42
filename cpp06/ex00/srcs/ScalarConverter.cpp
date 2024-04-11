/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 16:08:00 by codespace        ###   ########.fr       */
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






static void	print(char c)
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
		return (true);
	return (false);
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
/*
int is_int(std::string& str)
{
	int	i;
	int neg;
	long base;
	long expo;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	base = 0;
	while (str[i] && std::isdigit(str[i]))
	{
		base *= 10;
		if (base == std::numeric_limits<int>::max() / 10 &&
		(str[i] - '0'))
		base += str[i] - '0';
		i++;
	}


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

bool	too_many_args(std::string& word, std::string& literal)
{
	std::stringstream ss(literal);
	std::string dummy;

	ss >> word;
	if (ss >> dummy)
		return (true);
	return (false);
}

void	ScalarConverter::convert(std::string literal)
{
	std::string word;

	if (too_many_args(word, literal))
	{
		std::cout << "string literal has too many args" << std::endl;
		return ;
	}
	int pseudo = is_pseudo(word);
	if (pseudo)
		return (print_pseudo(word, pseudo));
	if (is_char(word))
		return (print(word[0]));
}
