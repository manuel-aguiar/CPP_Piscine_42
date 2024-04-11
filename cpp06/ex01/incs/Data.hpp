/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:41:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 12:38:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP

# define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	public:
		Data();
		~Data();
		Data(const Data& copy);
		Data& operator=(const Data& assign);

		std::string		a_string;
		int				a_number;
};


#endif
