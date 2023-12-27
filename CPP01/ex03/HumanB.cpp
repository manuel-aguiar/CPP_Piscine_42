#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    
}

HumanB::HumanB(const HumanB &copy) : name(copy.name)
{
    if (this == &copy)
        return ;
    this->name = copy.name;
    this->weapon = copy.weapon;
}

HumanB& HumanB::operator=(const HumanB &copy)
{
    if (this == &copy)
        return (*this);
    this->name = copy.name;
    this->weapon = copy.weapon;
    return (*this);
}

void    HumanB::attack()
{
    
    std::cout << this->name << " attacks with their ";
    std::cout << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

