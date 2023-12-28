/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_print.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:50:44 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:55:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::print_summary(void)
{
    this->print_padding(this->getFirst());
    this->print_padding(this->getLast());
    this->print_padding(this->getNick());
    std::cout << std::endl;
}

void Contact::print_full(void)
{
	std::cout << std::left << std::setw(12) << "First Name: ";
	std::cout << this->getFirst() << std::endl;
	std::cout << std::left << std::setw(12) << "Last Name: ";
	std::cout << this->getLast() << std::endl;
	std::cout << std::left << std::setw(12) << "Nick Name: ";
	std::cout << this->getNick() << std::endl;
	std::cout << std::left << std::setw(12) << "Phone: ";
	std::cout << this->getPhone() << std::endl;
	std::cout << std::left << std::setw(12) << "Secret: ";
	std::cout << this->getSecret() << std::endl;
}

void    Contact::print_padding(const std::string& member)
{
    std::cout << "|";
    if (member.size() <= 10)
	 std::cout << std::setw(10) << std::right << member;
    else
    {
	 std::cout.write(member.c_str(), 9);
	 std::cout.write(".", 2);
    }
}
