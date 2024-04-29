/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:38:48 by codespace         #+#    #+#             */
/*   Updated: 2024/04/29 13:53:14 by codespace        ###   ########.fr       */
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

		typedef typename std::stack<T,C>::container_type::iterator 					iterator;
		typedef typename std::stack<T,C>::container_type::const_iterator 			const_iterator;
		typedef typename std::stack<T,C>::container_type::reverse_iterator 			reverse_iterator;
		typedef typename std::stack<T,C>::container_type::const_reverse_iterator 	const_reverse_iterator;

		iterator 					begin(void);
		const_iterator				begin(void) const;

		iterator 					end(void);
		const_iterator				end(void) const;

		reverse_iterator			rbegin(void);
		const_reverse_iterator		rbegin(void) const;

		reverse_iterator			rend(void);
		const_reverse_iterator		rend(void) const;

		//void						sort(void);

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

/**********************************************/

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
>	typename std::stack<T,C>::container_type::const_iterator MutantStack<T,C>::begin(void) const
{
	return (std::stack<T,C>::c.begin());
}

/**********************************************/

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::iterator MutantStack<T,C>::end(void)
{
	return (std::stack<T,C>::c.end());
}

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::const_iterator MutantStack<T,C>::end(void) const
{
	return (std::stack<T,C>::c.end());
}

/***************************************************/

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::reverse_iterator MutantStack<T,C>::rbegin(void)
{
	return (std::stack<T,C>::c.rbegin());
}

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::const_reverse_iterator MutantStack<T,C>::rbegin(void) const
{
	return (std::stack<T,C>::c.rbegin());
}

/**********************************************/

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::reverse_iterator MutantStack<T,C>::rend(void)
{
	return (std::stack<T,C>::c.rend());
}

template<
	class T,
	class C
>	typename std::stack<T,C>::container_type::const_reverse_iterator MutantStack<T,C>::rend(void) const
{
	return (std::stack<T,C>::c.rend());
}

/***************************************************/

/*
template<
	class T,
	class C
>	void MutantStack<T,C>::sort(void)
{
	return (std::stack<T,C>::c.sort());
}
*/

#endif
