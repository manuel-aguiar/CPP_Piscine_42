/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 11:23:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <set>
#include <limits>

class Span
{
	public:
		Span(const size_t capacity);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& assign);

		unsigned long int	shortestSpan(void) const;
		unsigned long int 	longestSpan(void) const;
		void				addNumber(const int num);
		void				addBatch(const size_t count);
		void				print_numbers(void) const;

		const std::set<int>&	get_numbers(void) const;

		int		operator++(int);
		int		operator++(void);

	private:
		Span();
		size_t			_total_capacity;
		size_t			_used_capacity;
		bool			_doubled_entry;
		std::set<int>	_numbers;
		int				_add_rand_int(void);


		//helper struct to print numbers using std::for_each
		//c++98 doesn't allow lambedas, can't overload << as i wanted :(
		struct PrintElement
		{
				// interesting overload, never thought of this, tks chatgpt
				// function call via PrintElement(), where for_each will
				// dump the number (const int& as it is a set)
				void operator()(const int& n) const
				{
					std::cout << n << std::endl;
				}
		};

		struct GetShortest
		{
			void operator()(const int& n)
			{
				if (_shortest == 0)
					_shortest = std::numeric_limits<int>::max();
				else if (n - _save < _shortest)
					_shortest = n - _save;
				_save = n;
			}
			int		_shortest;
			int		_save;
		};
};


//setting srand for adding a batch of numbers
extern int g_rand_seed;


#endif
