#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{

}

HumanB::HumanB(const HumanB& copy) : name(copy.name)
{
    if (this == &copy)
        return ;
}

HumanB& HumanB::operator=(const HumanB& assign)
{
    if (this == &assign)
        return (*this);
    this->name = assign.name;
    this->weapon = assign.weapon;
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

