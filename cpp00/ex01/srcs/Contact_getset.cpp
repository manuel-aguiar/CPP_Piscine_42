/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_getset.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:04:47 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:05:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::getFirst() const
{
    return (this->first);
}

const std::string& Contact::getLast() const
{
    return (this->last);
}

const std::string& Contact::getNick() const
{
    return (this->nick);
}

const std::string& Contact::getPhone() const
{
    return (this->phone);
}

const std::string& Contact::getSecret() const
{
    return (this->secret);
}

void Contact::setFirst(const std::string& value)
{
    this->first = value;
}

void Contact::setLast(const std::string& value)
{
    this->last = value;
}

void Contact::setNick(const std::string& value)
{
    this->nick = value;
}

void Contact::setPhone(const std::string& value)
{
    this->phone = value;
}

void Contact::setSecret(const std::string& value)
{
    this->secret = value;
}
