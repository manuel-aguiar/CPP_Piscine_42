/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:38:48 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 16:05:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP

# define MUTANTSTACK_TPP

#include <iostream>
#include <stack>

template<class T, class C = std::deque<T> >
class MutantStack : public std::stack<T,C>
{

};


#endif
