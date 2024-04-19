/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_parsing.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:58:42 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 11:40:11 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

bool RPN::parse(void)
{
    if (_arg.find_first_not_of(VALID_CHARS, 0) != std::string::npos
    || _arg.length() == 0 
    || !std::isdigit(_arg[0]))
    {
        CERR("RPN: invalid input");
        return (false);
    }
    std::stringstream ss(_arg);
    std::string word;
    while (ss >> word)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return (true);
}


bool    RPN::calculate(const std::string& op)
{
    switch (op[0])
    {
        case '+':
            return (sumation());
        case '-':
            return (subtraction());
    }
}

bool    RPN::sumation(void)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "sumation" << std::endl;
    #endif
    return (true);
}

bool    RPN::subtraction(void)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "subtraction" << std::endl;
    #endif
    return (true);
}

bool    RPN::multiplication(void)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "multiplication" << std::endl;
    #endif
    return (true);
}

bool    RPN::division(void)
{
    #ifdef DEBUG_OPERATORS
        std::cout << "division" << std::endl;
    #endif
    return (true);
}