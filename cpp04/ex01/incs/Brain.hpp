/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:47:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

#include <string>
#include <cstring>
#include <iostream>

#define NUMBER_IDEAS 100

class Brain
{
    public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain& operator= (const Brain& assign);

		const std::string&	getIdeas(const unsigned int index) const;
		void				setIdeas(const unsigned int index, const std::string& thought);
    private:
		std::string ideas[NUMBER_IDEAS];
};

#endif
