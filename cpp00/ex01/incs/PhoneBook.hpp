/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:38 by codespace         #+#    #+#             */
/*   Updated: 2023/12/27 11:45:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <list>
# include <map>
# include <iomanip>
# include <cctype>
# include "Contact.hpp"

# define MAX_CONTACTS 8
# define PB_FUNCTIONS 5

class PhoneBook
{
    public:

        PhoneBook ();
        PhoneBook (const PhoneBook &copy);
        ~PhoneBook ();
        PhoneBook &operator= (const PhoneBook &copy);

        void                    run_phonebook(void);

    private:

        typedef                 void (PhoneBook::*pbfunc)();
        typedef                 void (Contact::*Contact_setter)(const std::string &);

        //horsepower
        pbfunc                  functions[PB_FUNCTIONS];
        Contact                 list[MAX_CONTACTS];

        //phonebook stats
        bool                    running;
        int                     contact_count;
        int                     contacts_max;

        //main functions
        void                    greetings();
        void                    add_contact();
        void                    search_contact();
        void                    exit_phonebook();
        void                    help_phonebook();
        void                    error_phonebook();

        //helper functions
        bool                    readin_stdin(const std::string &ask_field, std::string &buffer, Contact &contact, Contact_setter setter);
        bool                    my_atoi(std::string &str, int &place_res, int &contact_count);
        void                    bad_contact_input();
        bool                    buffer_is_only_space(std::string &buffer);
        int                     string_to_action(std::string& buffer);
};


# define ACT_ADD "ADD"
# define ACT_SEARCH "SEARCH"
# define ACT_EXIT "EXIT"
# define ACT_HELP "HELP"

enum action
{
    ENU_ADD,
    ENU_SEARCH,
    ENU_EXIT,
    ENU_HELP,
    ENU_ERROR,
};





/*

LEGACY

class PhoneBook
{
    public:

        PhoneBook ();
        PhoneBook (const PhoneBook &copy);
        ~PhoneBook ();
        PhoneBook &operator= (const PhoneBook &copy);

        void                    run_phonebook(void);

    private:

        typedef                 void (PhoneBook::*pbfunc)();
        typedef                 void (Contact::*Contact_setter)(const std::string &);
        std::map                <std::string, pbfunc> functions;
        std::list               <Contact> list;

        bool                    running;
        int                     contacts_max;
        void                    greetings();
        void                    add_contact();
        void                    search_contact();
        void                    exit_phonebook();
        void                    help_phonebook();
        bool                    readin_stdin(const std::string &ask_field, std::string &buffer, Contact &contact, Contact_setter setter);
        bool                    my_atoi(std::string &str, int &place_res, std::list<Contact>::size_type num_entries);
        void                    bad_contact_input();
        bool                    buffer_is_only_space(std::string &buffer);
};


*/

#endif
