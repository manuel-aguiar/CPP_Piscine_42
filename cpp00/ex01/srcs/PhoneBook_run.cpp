/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_run.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:51:44 by codespace         #+#    #+#             */
/*   Updated: 2024/03/13 11:18:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

void    PhoneBook::run_phonebook()
{
	std::string buffer;

	this->greetings();
	while (this->running)
	{
		std::cout << "Tell me: ";
		if (!std::getline(std::cin, buffer))
		{
			std::cout << "\nStdin is closed :( must exit, bye!!" << std::endl;
			this->running = false;
			return ;
		}
		(this->*functions[this->string_to_action(buffer)])();
	}
}

bool    PhoneBook::readin_stdin(const std::string& ask_field, std::string& buffer, Contact& contact, Contact_setter setter)
{
	std::cout << std::left << std::setw(12) << ask_field;
	if (!std::getline(std::cin, buffer))
	{
		std::cout << "\nStdin is closed :( must exit, bye!!" << std::endl;
		this->running = false;
		return (false);
	}
	if (this->buffer_is_only_space(buffer))
	{
		this->bad_contact_input();
		return (false);
	}
	else
		(contact.*setter)(buffer);
	return(true);
}

void    PhoneBook::add_contact()
{
	Contact     contact;
	std::string buffer;

	if (!this->readin_stdin("First Name: ", buffer, contact, &Contact::setFirst) \
	|| !this->readin_stdin("Last Name: ", buffer, contact, &Contact::setLast) \
	|| !this->readin_stdin("Nick Name: ", buffer, contact, &Contact::setNick) \
	|| !this->readin_stdin("Number: ", buffer, contact, &Contact::setPhone) \
	|| !this->readin_stdin("Secret: ", buffer, contact, &Contact::setSecret))
		return ;
	for (int i = this->contact_count; i > 0; i--)
	{
		if (i != this->contacts_max)
			this->list[i] = this->list[i - 1];
	}
	this->list[0] = contact;
	this->contact_count += (this->contact_count < this->contacts_max);
}

void    PhoneBook::search_contact()
{
	std::string			buffer;
	int				 	index;

	for(index = 0; index < this->contact_count; index++)
	{
		std::cout << std::setw(10) << std::right << index;
		this->list[index].print_summary();
	}
	std::cout << "Index: ";
	if (!std::getline(std::cin, buffer))
	{
		std::cout << "\nStdin is closed :( must exit, bye!!" << std::endl;
		this->running = false;
		return ;
	}
	if (this->my_atoi(buffer, index, this->contact_count) == false)
	{
		std::cout << "Not a valid index :(" << std::endl;
		return ;
	}
	this->list[index].print_full();
}

void    PhoneBook::exit_phonebook()
{
	this->running = 0;
}


void    PhoneBook::greetings()
{
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	this->help_phonebook();
}

void    PhoneBook::help_phonebook()
{
	std::cout << "Usage:" << std::endl;
	std::cout << std::left << std::setw(8) << "ADD";
	std::cout << "- save a new contact;" << std::endl;
	std::cout << std::left << std::setw(8) << "SEARCH";
	std::cout << "- display a specific contact;" << std::endl;
	std::cout << std::left << std::setw(8) << "EXIT";
	std::cout << "- exit the PhoneBook (contacts will be lost!!!);" << std::endl;
	std::cout << std::left << std::setw(8) << "HELP";
	std::cout << "- see all functionalities;" << std::endl;
}

void    PhoneBook::error_phonebook()
{
	std::cout << "Ops, wrong Input!!" << std::endl;
	this->help_phonebook();
}

void    PhoneBook::bad_contact_input()
{
	std::cout << "Ops!! Contact data must not be empty! Contact was NOT added!" << std::endl;
}
