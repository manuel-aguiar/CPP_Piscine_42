/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:26:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/06 14:17:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterators.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

int main(void)
{
    std::list<int> list;
    std::vector<int> vec;

    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
        vec.push_back(i);
    }

	GroupIterator<std::vector<int>::iterator> gvec(vec.begin(), 3);
    std::cout << "Vector iterator: " << gvec[0] << std::endl; // Should print 2

	GroupIterator<std::list<int>::iterator> glist(list.begin(), 1);
	GroupIterator<std::list<int>::iterator> gliste(list.end(), 1);
    std::cout << "List iterator: " << std::binary_search(glist, gliste, 6) << std::endl; // Should print 2


    return 0;
}

