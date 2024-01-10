/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 10:29:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator= (const WrongAnimal& assign);

		const std::string&	getType(void) const;

		void	makeSound(void) const;

    protected:
		std::string type;
};

#endif
