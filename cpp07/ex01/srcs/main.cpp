/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:33 by manuel            #+#    #+#             */
/*   Updated: 2024/04/12 17:10:46 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    super_specific_std_string_cout(std::string& str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    {
        int arr[5] = {1,2,3,4,5};
        size_t len = sizeof(arr) / sizeof(arr[0]);
        
        ::print_arr(arr, len);
        ::iter(arr, len, ::double_val);
        ::print_arr(arr, len);
        std::cout << std::endl;

        
        ::iter(arr, len, ::double_val);
        ::iter(arr, len, ::print_cout);
        std::cout << std::endl;
    }

    {
        std::string arr[5] = {"yoyoyo","yayaya","stfu bro","yo mad","tttttriparia"};
        size_t len = sizeof(arr) / sizeof(arr[0]);
        std::cout << sizeof(arr) << "    " << sizeof(arr[0]) << std::endl;
        ::iter(arr, len, ::print_cout);
        std::cout << std::endl;
    }

    {
        std::string arr[5] = {"yoyoyo","yayaya","stfu bro","yo mad","tttttriparia"};
        size_t len = sizeof(arr) / sizeof(arr[0]);
        
        ::iter(arr, len, super_specific_std_string_cout);
    }

    return (0);
}