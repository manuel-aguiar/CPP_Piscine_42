/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:02:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/12 11:56:53 by manuel           ###   ########.fr       */
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


static int	is_pseudo(const std::string& str)
{
	if (str == "+inf" || str == "-inf")
		return (PSEUDO_DOUBLE);
	if (str == "+inff" || str == "-inff")
		return (PSEUDO_FLOAT);
	if (str == "nan" || str == "nanf")
		return (PSEUDO_NAN);
	return (0);
}

static int	is_char(std::string& word)
{
	if (word.length() == 1
	&& ((word[0] >= 32 && word[0] < '0')
	|| (word[0] > '9' && word[0] <= 126)))
		return (CHAR);
	return (ERROR);
}

static int is_number(std::string& str)
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



static void	print_pseudo(std::string& word, int type)
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

static void	print_error(void)
{
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: impossible\n"
				<< "double: impossible" << std::endl;
}

static void	print_int(std::string& word)
{
	long 	conversion;

	conversion = std::strtol(word.c_str(), NULL, 10);
	
	//print CHAR
	if (conversion < -128 || conversion > 127)
		std::cout << "char: impossible\n";
	else if (conversion < 32)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(conversion) << "'\n";
	
	// print INT
	if (conversion > std::numeric_limits<int>::max()
	 || conversion < std::numeric_limits<int>::min())
	 	std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(conversion) << '\n';
	
	// print FLOAT
	std::cout << "float: ";
	if (conversion > std::numeric_limits<float>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f\n";

	// print DOUBLE
	std::cout << "double: ";
	if (conversion > std::numeric_limits<double>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<double>(conversion);
	std::cout << std::endl;
}

static void	print_float(std::string& word)
{
	double conversion;

	conversion = std::strtod(word.c_str(), NULL);
	
	//print CHAR
	if (conversion < -128.0f || conversion > 127.0f)
		std::cout << "char: impossible\n";
	else if (conversion < 32.0f)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(conversion) << "'\n";
	
	// print INT
	if (conversion > std::numeric_limits<int>::max()
	 || conversion < std::numeric_limits<int>::min())
	 	std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(conversion) << '\n';
	
	// print FLOAT
	std::cout << "float: ";
	if (conversion > std::numeric_limits<float>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f\n";

	// print DOUBLE
	std::cout << "double: ";
	if (conversion > std::numeric_limits<double>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<double>(conversion);
	std::cout << std::endl;
}

static void	print_double(std::string& word)
{
	double conversion;

	conversion = std::strtod(word.c_str(), NULL);

	if (conversion < -128.0 || conversion > 127.0)
		std::cout << "char: impossible\n";
	else if (conversion < 32.0)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(conversion) << "'\n";
	
	// print INT
	if (conversion > std::numeric_limits<int>::max()
	 || conversion < std::numeric_limits<int>::min())
	 	std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(conversion) << '\n';
	
	// print FLOAT
	std::cout << "float: ";
	if (conversion > std::numeric_limits<float>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(conversion) << "f\n";

	// print DOUBLE
	std::cout << "double: ";
	if (conversion > std::numeric_limits<double>::max())
		std::cout << '+';
	std::cout << std::fixed << std::setprecision(1) << static_cast<double>(conversion);
	std::cout << std::endl;
}

static bool	too_many_args(std::string& word, std::string& literal)
{
	std::stringstream ss(literal);
	std::string dummy;

	ss >> word;
	if (ss >> dummy)
		return (true);
	return (false);
}

static int		find_type(std::string& word)
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
			return (print_int(word));
		case FLOAT:
			return (print_float(word));
		case DOUBLE:
			return (print_double(word));
		case PSEUDO_NAN:
			return (print_pseudo(word, type));
		case PSEUDO_FLOAT:
			return (print_pseudo(word, type));
		case PSEUDO_DOUBLE:
			return (print_pseudo(word, type));
	}
}
