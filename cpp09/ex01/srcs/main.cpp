/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:27 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 12:46:09 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        CERR("RPN: wrong number of arguments");
        return (1);
    }

    // try-catch potential <new> failures from containers
    try
    {
        RPN rpn(av[1]);
        if(!rpn.calculate())
        {
            CERR("RPN: invalid expression");
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
