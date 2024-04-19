/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:00:59 by manuel            #+#    #+#             */
/*   Updated: 2024/04/19 12:22:53 by manuel           ###   ########.fr       */
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
# include <cstdlib>

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
        bool        sumation(const int target);
        bool        subtraction(const int target);
        bool        multiplication(const int target);
        bool        division(const int target);

    private:
        RPN();

        bool    check_valid_chars(void) const;
        
        typedef enum
        {
            E_NUM,
            E_OP,
            E_ERROR,
        }   e_type;

        e_type deduce_type(const std::string& word);

        std::string              _arg;
        std::stack<int>          _operands;

};



# define CERR(x) std::cout << x << std::endl

#endif