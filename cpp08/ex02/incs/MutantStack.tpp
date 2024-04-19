/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:38:48 by codespace         #+#    #+#             */
/*   Updated: 2024/04/19 09:41:27 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP

# define MUTANTSTACK_TPP


# include <iostream>
# include <stack>

template<
	class T, 
	class C = std::deque<T> 
> class MutantStack : public std::stack<T,C>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack& operator=( const MutantStack& assign);

		typedef typename std::stack<T,C>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);
};

template<
	class T, 
	class C
>	MutantStack<T,C>::MutantStack()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MutantStack Default Constructor Called" << std::endl;
	#endif
}

template<
	class T,
	class C
>	MutantStack<T,C>::~MutantStack()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MutantStack Destructor Called" << std::endl;
	#endif
}

template<
	class T,
	class C
>	MutantStack<T,C>::MutantStack(const MutantStack& copy) : std::stack<T,C>(copy)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MutantStack Copy Constructor Called" << std::endl;
	#endif
}

template<
	class T,
	class C
>	MutantStack<T,C>&	MutantStack<T,C>::operator=(const MutantStack& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "MutantStack Copy Assignment Called" << std::endl;
	#endif
	if (this == &assign)
		return (*this);
	std::stack<T,C>::operator=(assign);
}

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::iterator MutantStack<T,C>::begin(void)
{
	return (std::stack<T,C>::c.begin());
}

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::iterator MutantStack<T,C>::end(void)
{
	return (std::stack<T,C>::c.end());
}

#endif
