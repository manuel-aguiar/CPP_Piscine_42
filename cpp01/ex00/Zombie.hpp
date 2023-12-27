/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:07:33 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 15:22:15 by codespace        ###   ########.fr       */
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
		const std::string&	get_namezz() const;

        void				announce (void);

    private:
        std::string name;
};


#endif
