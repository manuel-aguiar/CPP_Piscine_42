/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_parsing.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:58:42 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 12:25:21 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

bool RPN::parse(void)
{
    if (_arg.find_first_not_of(VALID_CHARS, 0) != std::string::npos
    || _arg.length() == 0 
    || !std::isdigit(_arg[0]))
        return (false);
    std::stringstream ss(_arg);
    std::string word;
    while (ss >> word)
    {
        if (word.length() == 1 
        && !std::isdigit(word[0]))
        {
            if (!calculate(word))
                return (false);
        }
        else
            _operands.push(std::strtol(word.c_str(), NULL, 10));

    }
    if (_operands.size() != 1)
        return (false);
    std::cout << _operands.top() << std::endl;
    return (true);
}

RPN::e_type  RPN::deduce_type(const std::string& word)
{
    (void)word;




    return (E_ERROR);
}

bool    RPN::calculate(const std::string& op)
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

bool    RPN::sumation(const int target)
{
    _operands.top() += target;
    #ifdef DEBUG_OPERATORS
        std::cout   << "sumation: prev top: " << _operands.top() - target 
                    << " target " << target
                    << " new top " << _operands.top() << std::endl;
    #endif
    return (true);
}

bool    RPN::subtraction(const int target)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "subtraction" << std::endl;
    #endif
    _operands.top() -= target;
    return (true);
}

bool    RPN::multiplication(const int target)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "multiplication" << std::endl;
    #endif
    _operands.top() *= target;
    return (true);
}

bool    RPN::division(const int target)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "division" << std::endl;
    #endif
     _operands.top() /= target;
    return (true);
}