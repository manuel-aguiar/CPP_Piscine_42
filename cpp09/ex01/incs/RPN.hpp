/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:00:59 by manuel            #+#    #+#             */
/*   Updated: 2024/05/09 15:26:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

    for dir in cpp0{0..9}; do for subdir in ${dir}/ex*; do (cd ${subdir} ; make fclean ; make git); done; done

*/

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>
# include <list>
# include <cctype>
# include <sstream>
# include <cstdlib>
# include <cerrno>

# define VALID_CHARS " 0123456789+-/*"

class RPN
{
    public:
        RPN(const std::string& str);
        ~RPN();
        RPN(const RPN& copy);
        RPN&    operator=(const RPN& assign);

        bool        calculate(void);


    private:
        RPN();

        bool        apply_operation		(const std::string& op);
        bool        sumation			(const double target);
        bool        subtraction			(const double target);
        bool        multiplication		(const double target);
        bool        division			(const double target);
        bool        check_valid_chars	(void) const;

        typedef enum
        {
            E_NUM,
            E_OP,
            E_ERROR,
        }   e_type;

        e_type deduce_type(const std::string& word);

        std::string              					_arg;
        std::stack<double, std::list<double> >        _operands;

};



# define CERR(x) std::cerr << x << std::endl

#endif
