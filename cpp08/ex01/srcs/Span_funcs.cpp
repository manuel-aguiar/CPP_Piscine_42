/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span_funcs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:41:55 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 15:31:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	call_srand(void)
{
	std::srand(std::time(0));
	return (1);
}

int g_rand_seed = call_srand();

size_t	Span::longestSpan() const
{
	if (_used_capacity <= 1)
		throw std::runtime_error("Span doesn't have enough numbers to calculate");
	return (*--(_numbers.end()) - *(_numbers.begin()));
}

size_t	Span::shortestSpan() const
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

void	Span::addBatch(const size_t count)
{
	size_t add = count;

	if (_total_capacity - _used_capacity < count)
		add = _total_capacity - _used_capacity;
	for (size_t i = 0; i < add; i++)
		_add_rand_int();
	if (add != count)
		throw std::runtime_error ("Span is already at max capacity");
}

int	Span::_add_rand_int(void)
{
	int num;

	if (_used_capacity == _total_capacity)
		throw std::runtime_error ("Span is already at max capacity");
	_used_capacity++;
	num = rand() - RAND_MAX / 2;
	_numbers.insert(num);
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
	//std::cout << "\nbefore   n " << n << " save " << _save << " _shortest " << _shortest << std::endl;
	_shortest = std::min(n - _save, _shortest);
	_save = n;
	//std::cout << "after   n " << n << " save " << _save << " _shortest " << _shortest << std::endl;
}
