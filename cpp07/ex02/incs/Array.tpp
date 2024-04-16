/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:51:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 14:58:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP

# define ARRAY_TPP

template <class T>
class Array
{
	public:
		Array();
		Array(const unsigned int n);
		~Array();
		Array(const Array& copy);
		Array& operator=(const Array& assign);

		unsigned int	size(void) const;
	private:
		unsigned int	_size;
};


#endif
