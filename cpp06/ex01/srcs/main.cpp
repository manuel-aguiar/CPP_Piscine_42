/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:33:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/11 12:39:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;

	std::cout << "Address of data: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized, raw: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized, ptr: " << ptr << std::endl;

}

/*

	It behaves like the worst case C-style cast

*/
