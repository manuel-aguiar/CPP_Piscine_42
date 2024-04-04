/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:28 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 15:30:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator= (const Cat& assign);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	private:
		Brain*	my_brain;
};


/*
	Making all the constructors protected would make it impossible
	to instantiate from main.

	Interestingly enough, you you put the constructors protected,
	derived can add them to their member initialization lists
	(pre-construction)
	but not at the function bodies :0
	Constructor Body is already post-construction


	So, actually, the constructors you inherit with "protected", can only be used
	in the subobject construction for this instance, and nothing else

	In a way, protected is quite restrictive as well:
		my constructors are available for you to build yourself
			but not to build a copy of me :)
*/

#endif
