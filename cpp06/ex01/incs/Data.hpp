/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:41:52 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 12:23:07 by codespace        ###   ########.fr       */
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

		int				a_number;
		std::string		a_string;
};


#endif
