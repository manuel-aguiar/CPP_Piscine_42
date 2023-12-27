#ifndef CONTACT_HPP

# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    public:
    
        Contact ();
        Contact (const Contact &copy);
        ~Contact ();
        Contact &operator= (const Contact &copy);
        
        const   std::string &getFirst() const;
        const   std::string &getLast() const;
        const   std::string &getNick() const;
        const   std::string &getPhone() const;
        const   std::string &getSecret() const;
        
        void    setFirst(const std::string &value);
        void    setLast(const std::string &value);
        void    setNick(const std::string &value);
        void    setPhone(const std::string &value);
        void    setSecret(const std::string &value);
        
        void    print_summary();
        void    print_full();
        
    private:
    
        void    print_padding(const std::string &member, std::string &buffer);
        
        std::string first;
        std::string last;
        std::string nick;
        std::string phone;
        std::string secret;
};


#endif