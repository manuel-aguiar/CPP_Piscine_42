/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:59:53 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 12:14:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H

# define HARL_H

# include <string>
# include <iostream>

# pragma GCC diagnostic ignored "-Wimplicit-fallthrough"

class Harl
{
    public:

		Harl();
		~Harl();
		Harl (const Harl& copy);
		Harl& operator= (const Harl& assign);

		void complain( std::string level );

    private:

		void	 debug(void);
		void	 info(void);
		void	 warning(void);
		void	 error(void);
		void	 noise(void);

		typedef     	void (Harl::*level)(void);
		level			funcs[5];
		std::string 	callers[5];
		int	  			num_levels;

		enum complaints
		{
	    	ENU_NOISE,
	    	ENU_DEBUG,
	    	ENU_INFO,
	    	ENU_WARNING,
	    	ENU_ERROR,
		};
};

#endif
