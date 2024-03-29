/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 11:53:49 by codespace        ###   ########.fr       */
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
	std::cout << "Brain Copy Constructor called" << std::endl;

	if (this == &copy)
		return ;

	for (int i = 0; i < NUMBER_IDEAS; i++)
		ideas[i] = copy.ideas[i];

}

Brain& Brain::operator= (const Brain& assign)
{
	std::cout << "Brain Copy Assignment called" << std::endl;

	if (this == &assign)
		return (*this);

	for (int i = 0; i < NUMBER_IDEAS; i++)
		ideas[i] = assign.ideas[i];

	return (*this) ;
}

const std::string& Brain::getIdeas(const unsigned int index) const
{
	if (index >= NUMBER_IDEAS)
		throw std::out_of_range("Index out of bounds");
	return (ideas[index]);
}

void	Brain::setIdeas(const unsigned int index, const std::string& thought)
{
	if (index >= NUMBER_IDEAS)
		throw std::out_of_range("Index out of bounds");
	ideas[index] = thought;
}
