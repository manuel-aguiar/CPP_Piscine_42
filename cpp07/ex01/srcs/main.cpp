/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:33 by manuel            #+#    #+#             */
/*   Updated: 2024/04/23 11:40:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

/*
	template <class T, class F>
	void iter(T arr[], size_t len, F func)
	{
		for (size_t i = 0; i < len; i++)
		{
			func(arr[i]);
		}
	}

	F is what is called a "Functor". It is essentially a class that
	overloads the operator () and can be used to pass functions
	to templates.

	It is for instance, what std::for_each receives.


	Vs the old prototype using void (*func)(T&), it allows greater flexibility.



*/

template<class T>
class functor
{
	public:
		functor() : _count(0) {}
		functor(const functor& copy) { _count = copy._count;}
		void operator()(T& ref)
		{
			std::cout << ref << std::endl;
			_count++;
		}
		int _count;
};

/*
	I used this in cpp08 to calculate the span, saving the lowest value
	inside the functor class and finally returning it
*/

int main(void)
{
	int arr[5] = {1,2,3,4,5};

	functor<int> func = iter(arr, 5, functor<int>());
	std::cout << func._count << std::endl;
}




/*


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
*/
