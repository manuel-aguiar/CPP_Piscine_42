#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
    this->type = type;
}

/*
Weapon::Weapon()
{

}*/

Weapon::~Weapon()
{

}

Weapon::Weapon(const Weapon& copy) : type(copy.type)
{
    if (this == &copy)
        return ;
}

Weapon& Weapon::operator=(const Weapon& assign)
{
    if (this == &assign)
        return (*this);
    this->type = assign.type;
    return (*this);
}

const std::string& Weapon::getType() const
{
    return (this->type);
}

void    Weapon::setType(const std::string& type)
{
    this->type = type;
}
