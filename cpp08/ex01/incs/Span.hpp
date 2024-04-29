/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/29 15:04:35 by codespace        ###   ########.fr       */
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
#include <vector>
#include <limits>

/*
	Purposefully not a very efficient solution.

	Instead of Vector and a call to std::sort everytime you want to calculate the longest
	span, std::set rebalances (costly) the RB-tree on every insert, keeping it sorted.
	So .begin() - --.end() will be the longest span.
	Iteration using std::for_each


	Vector looks like the best case. The resize operation doesn't take place very often.
	Then go for std::sort, or even stable_sort to preserve order of equals, if that is
	important.

	Set should be better if you want to find if an element is a part of it, on average
	but this is not a case of frequent lookups and few insertions/deletions

	I didn't know anything about set, so now is about time!!!

	Still fun.
*/

class Span
{
	public:
		Span(const size_t capacity);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& assign);

		size_t				shortestSpan(void) const;
		size_t 				longestSpan(void) const;
		void				addNumber(const int num);
		void				addBatch(const size_t count);
		void				addBatch(int start, int end);
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

			PrintElement();
			~PrintElement();
			PrintElement(const PrintElement& copy);
			PrintElement& operator=(const PrintElement& assign);



			void operator()(const int& n) const;
		};

		struct GetShortest
		{
			GetShortest();
			~GetShortest();
			GetShortest(const GetShortest& copy);
			GetShortest& operator=(const GetShortest& assign);

			void 		operator()(const int& n);
			size_t		_shortest;
			size_t		_save;
		};
};


//setting srand for adding a batch of numbers
extern int g_rand_seed;


#endif
