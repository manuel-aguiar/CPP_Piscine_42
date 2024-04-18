/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:38:48 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 16:43:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP

# define MUTANTSTACK_TPP

#include <iostream>
#include <stack>

template<class T, class C = std::deque<T> >
class MutantStack : public std::stack<T,C>
{
	public:
		MutantStack() :
			std::stack<T,C>()
		{

		};
		~MutantStack(){

		};
		MutantStack( const MutantStack& copy) :
			std::stack<T,C>(copy)
		{

		};
		MutantStack& operator=( const MutantStack& assign)
		{
			if (this == &assign)
				return (*this);
			std::stack<T,C>::operator=(assign);
		};

		typedef typename std::stack<T,C>::container_type::iterator iterator;

		iterator begin(void)
		{
			return (std::stack<T,C>::c.begin());
		}

		iterator end(void)
		{
			return (std::stack<T,C>::c.end());
		}
};


#endif
