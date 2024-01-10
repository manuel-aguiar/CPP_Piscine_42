/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 11:11:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	if (this == &copy)
		return ;
	std::memcpy((void *)copy.ideas, (void *)ideas, sizeof(copy.ideas));
}

Brain& Brain::operator= (const Brain& assign)
{
	if (this == &assign)
		return (*this);
	std::memcpy((void *)assign.ideas, (void *)ideas, sizeof(assign.ideas));
	return (*this) ;
}
