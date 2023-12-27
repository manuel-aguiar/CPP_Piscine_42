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

Weapon::Weapon(const Weapon &copy)
{
    if (this == &copy)
        return ;
    this->type = copy.type;
}

Weapon& Weapon::operator=(const Weapon &copy)
{
    if (this == &copy)
        return (*this);
    this->type = copy.type;
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
