/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/04/30 14:37:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        CERR("Error: wrong number of arguments");
        return (1);
    }

    // try-catch potential <new> failures, and division by 0
    try
    {
        RPN rpn(av[1]);
        if(!rpn.calculate())
        {
            CERR("Error: invalid expression");
            return (1);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}
