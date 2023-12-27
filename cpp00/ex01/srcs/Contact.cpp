/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:24 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 13:10:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ()
{
    //std::cout << "constructed!!" << std::endl;
}

Contact::~Contact ()
{
    //std::cout << "destructed!!" << std::endl;
}

Contact::Contact (const Contact &copy)
{
    this->first = copy.first;
    this->last = copy.last;
    this->nick = copy.nick;
    this->phone = copy.phone;
    this->secret = copy.secret;
}

Contact &Contact::operator= (const Contact& assign)
{
    if (this == &assign)
        return (*this);
    this->first = assign.first;
    this->last = assign.last;
    this->nick = assign.nick;
    this->phone = assign.phone;
    this->secret = assign.secret;
    return (*this);
}

const std::string &Contact::getFirst() const
{
    return (this->first);
}

const std::string &Contact::getLast() const
{
    return (this->last);
}

const std::string &Contact::getNick() const
{
    return (this->nick);
}

const std::string &Contact::getPhone() const
{
    return (this->phone);
}

const std::string &Contact::getSecret() const
{
    return (this->secret);
}

void Contact::setFirst(const std::string &value)
{
    this->first = value;
}

void Contact::setLast(const std::string &value)
{
    this->last = value;
}

void Contact::setNick(const std::string &value)
{
    this->nick = value;
}

void Contact::setPhone(const std::string &value)
{
    this->phone = value;
}

void Contact::setSecret(const std::string &value)
{
    this->secret = value;
}

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
