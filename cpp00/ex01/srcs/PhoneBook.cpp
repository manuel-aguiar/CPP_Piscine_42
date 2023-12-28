/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:51:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 15:55:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook ()
{
	this->running = true;
	this->contact_count = 0;
	this->contacts_max = MAX_CONTACTS;
	this->functions[ENU_ADD] = &PhoneBook::add_contact;
	this->functions[ENU_SEARCH] = &PhoneBook::search_contact;
	this->functions[ENU_EXIT] = &PhoneBook::exit_phonebook;
	this->functions[ENU_HELP] = &PhoneBook::help_phonebook;
	this->functions[ENU_ERROR] = &PhoneBook::error_phonebook;
}

PhoneBook::~PhoneBook ()
{

}

PhoneBook::PhoneBook (const PhoneBook& copy)
{
	if (this == &copy)
		return ;
	this->running = copy.running;
	this->contact_count = copy.contact_count;
	this->contacts_max = copy.contacts_max;
	this->functions[ENU_ADD] = copy.functions[ENU_ADD];
	this->functions[ENU_SEARCH] = copy.functions[ENU_SEARCH];
	this->functions[ENU_EXIT] = copy.functions[ENU_EXIT];
	this->functions[ENU_HELP] = copy.functions[ENU_HELP];
	this->functions[ENU_ERROR] = copy.functions[ENU_ERROR];

	for (int i = 0; i < this->contact_count; i++)
		this->list[i] = copy.list[i];
}


PhoneBook &PhoneBook::operator=(const PhoneBook& assign)
{
	if (this == &assign)
		return (*this);
	this->functions[ENU_ADD] = assign.functions[ENU_ADD];
	this->functions[ENU_SEARCH] = assign.functions[ENU_SEARCH];
	this->functions[ENU_EXIT] = assign.functions[ENU_EXIT];
	this->functions[ENU_HELP] = assign.functions[ENU_HELP];
	this->functions[ENU_ERROR] = assign.functions[ENU_ERROR];

	this->running = assign.running;
	this->contacts_max = assign.contacts_max;

	for (int i = 0; i < this->contact_count; i++)
		this->list[i] = assign.list[i];
	return (*this);
}

