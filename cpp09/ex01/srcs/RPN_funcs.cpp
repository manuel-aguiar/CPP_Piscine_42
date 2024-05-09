/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_funcs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:58:42 by manuel            #+#    #+#             */
/*   Updated: 2024/05/09 15:32:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

bool RPN::calculate(void)
{
	if (_arg.find_first_not_of(VALID_CHARS, 0) != std::string::npos
	|| _arg.length() == 0)
		return (false);
	std::stringstream ss(_arg);
	std::string word;
	while (ss >> word)
	{
		switch(deduce_type(word))
		{
			case E_NUM:
			{
				_operands.push(std::strtol(word.c_str(), NULL, 10));
				if (errno == ERANGE)
					return (false);
				break ;
			}
			case E_OP:
			{
				if (!apply_operation(word))
					return (false);
				break ;
			}
			case E_ERROR:
				return (false);
		}
	}
	if (_operands.size() != 1)
		return (false);

	//blabla print double if double, otherwise print int
	int num = static_cast<int>(_operands.top());
	if (_operands.top() == static_cast<double>(num))
		std::cout << num << std::endl;
	else
		std::cout << _operands.top() << std::endl;
	return (true);
}

RPN::e_type  RPN::deduce_type(const std::string& word)
{
	if (word.length() == 1
	&& !std::isdigit(word[0]))
		return (E_OP);

	//DUMB ATOI
	int i = 0;
	if (word[i] == '+' || word[i] == '-')
		i++;
	if (word[i] && !std::isdigit(word[i]))
		return (E_ERROR);
	while (word[i] && std::isdigit(word[i]))
		i++;
	if (word[i] == '\0')
		return (E_NUM);
	return (E_ERROR);
}

bool    RPN::apply_operation(const std::string& op)
{
	if (_operands.size() < 2)
		return (false);
	int top = _operands.top();
	_operands.pop();
	switch (op[0])
	{
		case '+':
			return (sumation(top));
		case '-':
			return (subtraction(top));
		case '*':
			return (multiplication(top));
		case '/':
			return (division(top));
	}
	return (false);
}

inline bool    RPN::sumation(const double target)
{
	_operands.top() += target;
	#ifdef DEBUG_OPERATORS
		std::cout   << "sumation:  target " << target
					<< " new top " << _operands.top() << std::endl;
	#endif
	return (true);
}

inline bool    RPN::subtraction(const double target)
{
	_operands.top() -= target;
	#ifdef DEBUG_OPERATORS
		std::cout   << "subtraction:  target " << target
					<< " new top " << _operands.top() << std::endl;
	#endif
	return (true);
}

inline bool    RPN::multiplication(const double target)
{
	_operands.top() *= target;
	#ifdef DEBUG_OPERATORS
		std::cout   << "multiplication:  target " << target
					<< " new top " << _operands.top() << std::endl;
	#endif
	return (true);
}

inline bool    RPN::division(const double target)
{
	if (target == 0)
		throw std::runtime_error("Error: division by zero.");
	 _operands.top() /= target;
	#ifdef DEBUG_OPERATORS
		std::cout   << "division:  target " << target
					<< " new top " << _operands.top() << std::endl;
	#endif
	return (true);
}
