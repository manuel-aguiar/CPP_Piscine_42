/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 09:28:13 by codespace        ###   ########.fr       */
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
#include <iterator>

/*
	Purposefully not a very efficient solution.

	Instead of Vector and a call to std::sort everytime you want to calculate the longest
	span, std::set rebalances (costly) the RB-tree on every insert, keeping it sorted.
	So .rbegin() - .begin() will be the longest span.
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

		long				shortestSpan(void) const;
		long 				longestSpan(void) const;
		void				addNumber(const int num);

		//batch functions, for all tastes :)
		void				addBatch(const size_t count);
		void				addBatch(int start, int end);
		template <typename Iterator>
		void				addBatch(const Iterator& begin, const Iterator& end);

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
			GetShortest(const std::set<int>& set);
			~GetShortest();
			GetShortest(const GetShortest& copy);
			GetShortest& operator=(const GetShortest& assign);

			void 		operator()(const int& n);
			long		_shortest;
			long		_save;
		};
};


//setting srand for adding a batch of numbers
extern int g_rand_seed;

//template function for iterators
template <typename Iterator>
void	Span::addBatch(const Iterator& begin, const Iterator& end)
{
	size_t save_size = _numbers.size();
	int check = std::distance(begin, end);
	if (check <= 0)
		throw std::runtime_error ("Negative insertion distance passed to addBatch");
	size_t add = check;
	size_t save_add = add;
	if (_total_capacity - _used_capacity < add)
		add = _total_capacity - _used_capacity;
	if (add != save_add)
	{
		/*oh boy... std::next c++11 would be helpful*/
		Iterator new_end = begin;
		for (size_t i = 0; i < add; ++i)
			++new_end;
		_numbers.insert(begin, new_end);
	}
	else
		_numbers.insert(begin, end);
	_used_capacity += add;
	if (_numbers.size() - save_size != add)
		_doubled_entry = true;
	if (add != save_add)
		throw std::runtime_error ("Span is already at max capacity");
}


#endif
