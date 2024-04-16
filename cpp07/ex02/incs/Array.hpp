/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 15:50:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

# define ARRAY_HPP

#include <stdexcept>
#include <exception>

template <class T>
class Array
{
	public:
		Array();
		Array(const unsigned int n);
		~Array();
		Array(const Array<T>& copy);
		Array& operator=(const Array<T>& assign);
		T&	operator[](const size_t index);

		size_t			size(void) const;
	private:
		size_t			_size;
		T*				_arr;
};

# include "Array.tpp"

#endif
