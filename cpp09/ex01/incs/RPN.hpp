/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:00:59 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 10:48:32 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

    for dir in cpp0{0..9}; do for subdir in ${dir}/ex*; do (cd ${subdir} ; make fclean ; make git); done; done

*/

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>




class RPN
{
    public:
        RPN(const std::string& str);
        ~RPN();
        RPN(const RPN& copy);
        RPN&    operator=(const RPN& assign);



    private:
        RPN();
        std::string         _arg;
        std::stack<int>     _operands;

};



# define CERR(x) std::cerr << x << std::endl

#endif