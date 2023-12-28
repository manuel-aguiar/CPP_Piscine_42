/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:24 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:06:23 by codespace        ###   ########.fr       */
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
	if (this == &copy)
        return ;
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
