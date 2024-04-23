/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:33 by manuel            #+#    #+#             */
/*   Updated: 2024/04/23 13:43:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

/*
	template <class T, class F>
	F iter(T arr[], size_t len, F func)
	{
		for (size_t i = 0; i < len; i++)
		{
			func(arr[i]);
		}
		return (func);
	}

	F is what is called a "Functor". It is essentially a class that
	overloads the operator () and can be used to pass functions
	to templates.

	It is for instance, what std::for_each receives.
	std::for_each returns the function class itself in case the user
	needs access to variables within the class

	Vs the old prototype using void (*func)(T&), it allows greater flexibility.



*/

template<class T>
class Functor
{
	public:
		Functor() : _count(0)
		{
			std::cout << "Functor default" << std::endl;
		}

		~Functor()
		{
			std::cout << "Functor destructor" << std::endl;
		}

		Functor(const Functor& copy) : _count(copy._count)
		{
			std::cout << "Functor copy" << std::endl;
			*this = copy;
		}

		Functor& operator=(const Functor& assign)
		{
			std::cout << "Functor assignment" << std::endl;
			_count = assign._count;
			return (*this);
		}

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

void	print_int(const int &num)
{
	std::cout << num << std::endl;
}

void	print_string(const std::string& str)
{
	std::cout << str << std::endl;
}

/*####################################################################*/

/*******************************MAIN***********************************/

/*####################################################################*/


int main(void)
{
	int arr[5] = {123,123,123,123,123};

/*####################################################################*/
	std::cout << "\nfunctor copy class: " << std::endl;

	Functor<int> func = iter(arr, 5, Functor<int>());
	std::cout << "array count: " << func._count << std::endl;


/*####################################################################*/
	std::cout << "\nfunctor pointer class: " << std::endl;


	Functor<int> func_ptr;
	iter(arr, 5, &func_ptr);
	std::cout << "array count: " << func_ptr._count << std::endl;

/*####################################################################*/
	std::cout << "\ntemplate function: " << std::endl;

	iter(arr, 5, print_cout<int>);
	/*
		interesting, calling the pointer template, compiler deems more fit
	*/
/*####################################################################*/

	std::cout << "\ncalling function pointer template with 'NULL': " << std::endl;
	/*
		iter(arr, 5, NULL);
	*/
	std::cout << "iter(arr, 5, NULL);  -> doesn't compile\n"
	<< "'In instantiation of ‘F iter(T*, size_t, F) [with T = int; F = long int; size_t = long unsigned int]’:"
	<< "error: ‘func’ cannot be used as a function'" << std::endl;


/*####################################################################*/

	std::cout << "\nnon template - matching int function: " << std::endl;
	/*
		interesting, calling the pointer template, compiler deems more fit
	*/
	iter(arr, 5, print_int);

/*####################################################################*/


	std::cout << "\nnon template - non-matching std::string function:\n" << std::endl;
	std::cout << "iter(arr, 5, print_string);  -> doesn't compile\n"
	<< "'error: invalid initialization of reference of type"
	<< "‘const std::__cxx11::basic_string<char>&’ from expression of type ‘int’'" << std::endl;
	/*
		iter(arr, 5, print_string);
	*/

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
