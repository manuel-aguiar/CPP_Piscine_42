/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:02:22 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 11:52:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
		Zombie();
		~Zombie();
		Zombie(const Zombie& copy);
		Zombie &operator= (const Zombie& assign);

		void 				set_namezzz(const std::string& my_name);
		const std::string&	get_namezz(void) const;

		void				announce (void);

    private:
	 std::string name;
};



#endif
