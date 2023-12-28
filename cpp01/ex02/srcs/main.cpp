/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:01:09 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 16:01:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string     brain = "HI THIS IS BRAIN";
    std::string*    stringPTR = &brain;
    std::string&    stringREF = brain;

    std::cout << "Address of string object:			   " << &brain << std::endl;
    std::cout << "Address held by pointer to string:		 " << stringPTR << std::endl;
    std::cout << "Address held by reference to string:	      " << &stringREF << std::endl;

    std::cout << "Value of string object:			     " << brain << std::endl;
    std::cout << "Value at address held by pointer to string:      " << *stringPTR << std::endl;
    std::cout << "Value at address held by reference to string:    " << stringREF << std::endl;

    return (0);
}
