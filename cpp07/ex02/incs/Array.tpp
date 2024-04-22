/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:51:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/22 16:03:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP

# define ARRAY_TPP

template <class T>
Array<T>::Array() : _size(0), _arr(0)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Array Default Constructor called" << std::endl;
	#endif
}

template <class T>
Array<T>::Array(const unsigned int n) : _size(n), _arr(new T[_size])
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Array Default Constructor called" << std::endl;
	#endif
}

template <class T>
Array<T>::~Array()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Array Destructor called" << std::endl;
	#endif
	delete [] _arr;
}

template <class T>
Array<T>::Array(const Array<T>& copy) : _size(copy._size), _arr(new T[_size])
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Array Copy Constructor called" << std::endl;
	#endif
	for (size_t i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "Array Copy Assignment called" << std::endl;
	#endif
	if (_size != assign._size)
	{
		if (_arr)
			delete [] _arr;
		_arr = new T[assign._size];
		_size = assign._size;
	}
	for (size_t i = 0; i < _size; i++)
		_arr[i] = assign._arr[i];
	return (*this);
}

template <class T>
T&	Array<T>::operator[](const size_t index)
{
	if (index >= _size || index < 0)
		throw std::out_of_range("Index is out of range");
	return (_arr[index]);
}

template <class T>
size_t Array<T>::size(void) const
{
	return (_size);
}

#endif
