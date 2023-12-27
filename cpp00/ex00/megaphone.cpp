/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:30:49 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 10:31:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void capitalize_str(std::string &str)
{
    std::string::size_type  i;
    std::string::size_type  len;

    len = str.size();
    for (i = 0; i < len; i++)
        str[i] = std::toupper(str[i]);
}

int main(int ac, char **av)
{
    std::string loud;

    for (int i = 1; i < ac; i++)
    {
        loud = av[i];
        capitalize_str(loud);
        std::cout << loud;
    }
    std::cout << std::endl;
    return 0;
}
