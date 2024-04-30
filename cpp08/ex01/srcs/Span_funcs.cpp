/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span_funcs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:41:55 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 10:14:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	call_srand(void)
{
	std::srand(std::time(0));
	return (1);
}

int g_rand_seed = call_srand();

long	Span::longestSpan() const
{
	if (_used_capacity <= 1)
		throw std::runtime_error("Span doesn't have enough numbers to calculate");
	long res = *(_numbers.rbegin());
	res -= *(_numbers.begin());
	return (res);
}

long	Span::shortestSpan() const
{
	if (_used_capacity <= 1)
		throw std::runtime_error("Span doesn't have enough numbers to calculate");
	if (_doubled_entry)
		return (0);

	Span::GetShortest shortest =
	std::for_each(
		_numbers.begin(),
		_numbers.end(),
		Span::GetShortest()
	);
	return (shortest._shortest);
}

void	Span::addNumber(const int num)
{
	if (_used_capacity == _total_capacity)
		throw std::runtime_error ("Span is already at max capacity");

	//check if the number is already there, counts for capacity but shortest span is 0
	std::pair<std::set<int>::iterator, bool> iter = _numbers.insert(num);
	if (iter.second == false)
		_doubled_entry = true;
	_used_capacity++;
}

/*
	Two versions of add-batch, random numbers or from-to.
	save_size variable to measure pre and post insertion.
	if numbers added is smaller than target, means at least
	one insertion failed and there is a duplicate entry
	Faster shortest span calculation, should be zero.
*/

void	Span::addBatch(const size_t count)
{
	size_t add = count;
	if (_total_capacity - _used_capacity < count)
		add = _total_capacity - _used_capacity;
	std::vector<int> new_nums;
	new_nums.reserve(add);
	for (size_t i = 0; i < add; ++i)
		new_nums.push_back(rand() - RAND_MAX / 2);
	size_t save_size = _numbers.size();
	_numbers.insert(new_nums.begin(), new_nums.end());
	_used_capacity += add;
	if (_numbers.size() - save_size != add)
		_doubled_entry = true;
	if (add != count)
		throw std::runtime_error ("Span is already at max capacity");
}

void	Span::addBatch(int start, int end)
{
	if (start > end)
		std::swap(start, end);
	size_t count = end - start + 1;
	size_t add = count;
	if (_total_capacity - _used_capacity < count)
		add = _total_capacity - _used_capacity;
	std::vector<int> new_nums;
	new_nums.reserve(add);
	for (size_t i = 0; i < add; ++i)
		new_nums.push_back(start + i);
	size_t save_size = _numbers.size();
	_numbers.insert(new_nums.begin(), new_nums.end());
	_used_capacity += add;
	if (_numbers.size() - save_size != add)
		_doubled_entry = true;
	if (add != count)
		throw std::runtime_error ("Span is already at max capacity");
}

int	Span::_add_rand_int(void)
{
	int num;

	if (_used_capacity == _total_capacity)
		throw std::runtime_error ("Span is already at max capacity");
	_used_capacity++;
	num = std::rand() - RAND_MAX / 2;
	std::pair<std::set<int>::iterator, bool> iter = _numbers.insert(num);
	if (iter.second == false)
		_doubled_entry = true;
	return(num);
}

int		Span::operator++(int)
{
	return (_add_rand_int());
}

int		Span::operator++(void)
{
	return (_add_rand_int());
}

void	Span::print_numbers(void) const
{
	std::for_each(_numbers.begin(), _numbers.end(), PrintElement());
}

void	Span::PrintElement::operator()(const int& n) const
{
	std::cout << n << std::endl;
}

void	Span::GetShortest::operator()(const int& n)
{
	#ifdef DEBUG_PROGRAM
		std::cout << "before: shortest::operator(), _shortest: " << _shortest << ", _save: " << _save << std::endl;
	#endif

	_shortest = std::min(n - _save, _shortest);
	_save = n;

	#ifdef DEBUG_PROGRAM
		std::cout << "after: shortest::operator(), _shortest: " << _shortest << ", _save: " << _save << std::endl;
	#endif
}
