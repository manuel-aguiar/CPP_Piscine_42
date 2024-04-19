/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:00:59 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 11:40:08 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

    for dir in cpp0{0..9}; do for subdir in ${dir}/ex*; do (cd ${subdir} ; make fclean ; make git); done; done

*/

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>
# include <sstream>

# define VALID_CHARS " 0123456789+-/*"

class RPN
{
    public:
        RPN(const std::string& str);
        ~RPN();
        RPN(const RPN& copy);
        RPN&    operator=(const RPN& assign);

        bool        parse(void);
        bool        calculate(const std::string& op);
        bool        sumation(void);
        bool        subtraction(void);
        bool        multiplication(void);
        bool        division(void);

    private:
        RPN();

        bool    check_valid_chars(void) const;


        std::string              _arg;
        std::stack<int>          _operands;

};



# define CERR(x) std::cout << x << std::endl

#endif