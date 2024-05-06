/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 09:27:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterators.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
    std::list<int> list;
    std::vector<int> vec;

    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
        vec.push_back(i);
    }

    // Test for list iterator
    std::list<int>::iterator listIt = list.begin();
    advanceIterator(listIt, 2);
    std::cout << "List iterator: " << *listIt << std::endl; // Should print 3

    // Test for vector iterator
    std::vector<int>::iterator vecIt = vec.begin();
    advanceIterator(vecIt, 2);
    std::cout << "Vector iterator: " << *vecIt << std::endl; // Should print 3

    return 0;
}

