/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 11:13:16 by codespace        ###   ########.fr       */
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
		virtual ~Brain();
		Brain(const Brain& copy);
		Brain& operator= (const Brain& assign);

		const std::string&	getIdeas(void) const;

    protected:
		std::string ideas[NUMBER_IDEAS];
};

#endif
