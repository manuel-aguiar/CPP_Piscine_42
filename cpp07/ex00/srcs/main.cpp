/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:46:23 by manuel            #+#    #+#             */
/*   Updated: 2024/04/12 16:26:46 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        return 0;
}

int main1(void)
{
    int i = 5;
    int j = 6;

    std::cout << "i: " << i << " j: " << j << std::endl;
    ::swap(i, j);
    std::cout << "i: " << i << " j: " << j << std::endl;

    std::string a("tretas");
    std::string b("cenas");

    std::cout << "i: " << a << " j: " << b << std::endl;
    ::swap(a, b);
    std::cout << "i: " << a << " j: " << b << std::endl;  

    return (0);
}