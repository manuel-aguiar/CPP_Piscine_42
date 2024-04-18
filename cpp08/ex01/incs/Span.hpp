/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 08:52:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <set>

class Span
{
	public:
		Span();
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& assign);

		int		shortestSpan(void) const;
		int 	longestSpan(void) const;
		void	addnumber(const int num);
		void	add_x_numbers(const size_t count);

		void	operator++(int);
		void	operator++(void);

	private:
		void				add_rand_int(void);
		int				rand_int(void);
		std::set<int>	numbers;
};

extern int g_rand_seed;


#endif
