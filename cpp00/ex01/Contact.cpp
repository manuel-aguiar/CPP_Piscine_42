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

Contact &Contact::operator= (const Contact &copy)
{
    if (this == &copy)
        return (*this);
    this->first = copy.first;
    this->last = copy.last;
    this->nick = copy.nick;
    this->phone = copy.phone;
    this->secret = copy.secret; 
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
    std::string str;
    
    this->print_padding(this->getFirst(), str);
    this->print_padding(this->getLast(), str);
    this->print_padding(this->getNick(), str);
    std::cout << std::endl;
}

void    Contact::print_padding(const std::string &member, std::string &buffer)
{
    buffer = member;
    std::cout << "|";
    if (buffer.size() <= 10)
        std::cout << std::setw(10) << std::right << buffer;
    else
    {
        std::cout.write(buffer.c_str(), 9);
        std::cout.write(".", 2);
    }    
}