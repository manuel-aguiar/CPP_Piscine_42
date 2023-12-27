/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:34 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 12:32:20 by codespace        ###   ########.fr       */
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

int    PhoneBook::string_to_action(std::string& buffer)
{
    if (!buffer.compare(ACT_ADD))
        return (ENU_ADD);
    if (!buffer.compare(ACT_SEARCH))
        return (ENU_SEARCH);
    if (!buffer.compare(ACT_EXIT))
        return (ENU_EXIT);
    if (!buffer.compare(ACT_HELP))
        return (ENU_HELP);
    return (ENU_ERROR);
}

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

bool    PhoneBook::readin_stdin(const std::string &ask_field, std::string &buffer, Contact &contact, Contact_setter setter)
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
    int         i;

    if (!this->readin_stdin("First Name: ", buffer, contact, &Contact::setFirst) \
    || !this->readin_stdin("Last Name: ", buffer, contact, &Contact::setLast) \
    || !this->readin_stdin("Nick Name: ", buffer, contact, &Contact::setNick) \
    || !this->readin_stdin("Number: ", buffer, contact, &Contact::setPhone) \
    || !this->readin_stdin("Secret: ", buffer, contact, &Contact::setSecret))
        return ;
    i = this->contact_count;
    while (i > 0)
    {
        if (i != this->contacts_max)
            this->list[i] = this->list[i - 1];
        i--;
    }

    this->list[0] = contact;
    this->contact_count += (this->contact_count < this->contacts_max);
}

bool     PhoneBook::my_atoi(std::string &str, int &place_res, int &contact_count)
{
    int res;
    int iter;

    res = 0;
    iter = 0;
    while (str[iter] && std::isspace(str[iter]))
        iter++;
    if (str[iter] && str[iter] == '-')
        return (false);
    if (str[iter] && str[iter] == '+')
        iter++;
    if (!str[iter] || (str[iter] && !std::isdigit(str[iter])))
        return (false);
    while (str[iter] && std::isdigit(str[iter]))
    {
        res = res * 10 + str[iter] - '0';
        if (res > contact_count - 1)
            return (false);
        iter++;
    }
    if (str[iter] && !std::isspace(str[iter]))
        return (false);
    place_res = res;
    return (true);
}

void    PhoneBook::search_contact()
{
    std::string                     buffer;
    int                             index;

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

    std::cout << std::left << std::setw(12) << "First Name: ";
    std::cout << this->list[index].getFirst() << std::endl;
    std::cout << std::left << std::setw(12) << "Last Name: ";
    std::cout << this->list[index].getLast() << std::endl;
    std::cout << std::left << std::setw(12) << "Nick Name: ";
    std::cout << this->list[index].getNick() << std::endl;
    std::cout << std::left << std::setw(12) << "Phone: ";
    std::cout << this->list[index].getPhone() << std::endl;
    std::cout << std::left << std::setw(12) << "Secret: ";
    std::cout << this->list[index].getSecret() << std::endl;
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

bool PhoneBook::buffer_is_only_space(std::string &buffer)
{
    std::string::size_type  i;
    std::string::size_type  len;

    len = buffer.size();
    for (i = 0; i < len; i++)
    {
        if (!std::isspace(buffer[i]))
            return (false);
    }
    return (true);
}

void    PhoneBook::bad_contact_input()
{
    std::cout << "Ops!! Contact data must not be empty! Contact was NOT added!" << std::endl;
}


/*

LEGACY CODE

PhoneBook::PhoneBook ()
{
    this->running = true;
    this->contacts_max = 8;
    this->functions["ADD"] = &PhoneBook::add_contact;
    this->functions["SEARCH"] = &PhoneBook::search_contact;
    this->functions["EXIT"] = &PhoneBook::exit_phonebook;
    this->functions["HELP"] = &PhoneBook::help_phonebook;
    this->greetings();
}

PhoneBook::~PhoneBook ()
{

}

PhoneBook::PhoneBook (const PhoneBook &copy)
{
    if (this == &copy)
        return ;
    this->functions = copy.functions;
    this->list = copy.list;
    this->running = copy.running;
    this->contacts_max = copy.contacts_max;
}


PhoneBook &PhoneBook::operator=(const PhoneBook &copy)
{
    if (this == &copy)
        return *this;
    this->functions = copy.functions;
    this->list = copy.list;
    this->running = copy.running;
    this->contacts_max = copy.contacts_max;
    return *this;
}

void    PhoneBook::run_phonebook()
{
    std::string buffer;

    while (this->running)
    {
        std::cout << "Tell me: ";
        std::cin >> buffer;
        if (std::cin.eof())
        {
            std::cout << "\nStdin is closed :( must exit, bye!!" << std::endl;
            this->running = false;
            return ;
        }
        if (this->functions.find(buffer) == this->functions.end())
        {
            std::cout << "Ops, wrong Input!!" << std::endl;
            this->help_phonebook();
        }
        else
            (this->*(functions[buffer]))();
    }
}

bool    PhoneBook::readin_stdin(const std::string &ask_field, std::string &buffer, Contact &contact, Contact_setter setter)
{
    std::cout << std::left << std::setw(12) << ask_field;
    std::cin >> buffer;
    if (std::cin.eof())
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

    if (this->list.size() == 8)
        this->list.pop_back();
    if (!this->readin_stdin("First Name: ", buffer, contact, &Contact::setFirst) \
    || !this->readin_stdin("Last Name: ", buffer, contact, &Contact::setLast) \
    || !this->readin_stdin("Nick Name: ", buffer, contact, &Contact::setNick) \
    || !this->readin_stdin("Number: ", buffer, contact, &Contact::setPhone) \
    || !this->readin_stdin("Secret: ", buffer, contact, &Contact::setSecret))
        return ;
    this->list.push_front(contact);
}

bool     PhoneBook::my_atoi(std::string &str, int &place_res, std::list<Contact>::size_type num_entries)
{
    std::list<Contact>::size_type   res;
    int                             iter;

    res = 0;
    iter = 0;
    while (str[iter] && std::isspace(str[iter]))
        iter++;
    if (str[iter] && str[iter] == '-')
        return (false);
    if (str[iter] && str[iter] == '+')
        iter++;
    if (str[iter] && !std::isdigit(str[iter]))
        return (false);
    while (str[iter] && std::isdigit(str[iter]))
    {
        res = res * 10 + str[iter] - '0';
        if (res > num_entries - 1)
            return (false);
        iter++;
    }
    if (str[iter] && !std::isspace(str[iter]))
        return (false);
    place_res = res;
    return (true);
}

void    PhoneBook::search_contact()
{
    std::list<Contact>::iterator    iter;
    std::string                     buffer;
    int                             index;

    index = 0;
    for(iter = this->list.begin(); iter != this->list.end(); iter++)
    {
        std::cout << std::setw(10) << std::right << index;
        (*iter).print_summary();
        index++;
    }
    std::cout << "Index: ";
    std::cin >> buffer;
    if (std::cin.eof())
    {
        std::cout << "\nStdin is closed :( must exit, bye!!" << std::endl;
        this->running = false;
        return ;
    }
    if (this->my_atoi(buffer, index, this->list.size()) == false)
    {
        std::cout << "Not a valid index :(" << std::endl;
        return ;
    }
    iter = this->list.begin();
    while (index-- != 0)
        iter++;
    std::cout << std::left << std::setw(12) << "First Name: ";
    std::cout << iter->getFirst() << std::endl;
    std::cout << std::left << std::setw(12) << "Last Name: ";
    std::cout << iter->getLast() << std::endl;
    std::cout << std::left << std::setw(12) << "Nick Name: ";
    std::cout << iter->getNick() << std::endl;
    std::cout << std::left << std::setw(12) << "Phone: ";
    std::cout << iter->getPhone() << std::endl;
    std::cout << std::left << std::setw(12) << "Secret: ";
    std::cout << iter->getSecret() << std::endl;
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

bool PhoneBook::buffer_is_only_space(std::string &buffer)
{
    std::string::size_type  i;
    std::string::size_type  len;

    len = buffer.size();
    for (i = 0; i < len; i++)
    {
        if (!std::isspace(buffer[i]))
            return (false);
    }
    return (true);
}

void    PhoneBook::bad_contact_input()
{
    std::cout << "Ops!! Contact data must not be empty! Contact was NOT added!" << std::endl;
}

*/
