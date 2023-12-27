#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon& weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{
    
}

HumanA::HumanA(const HumanA &copy) : name(copy.name), weapon(copy.weapon)
{
    if (this == &copy)
        return ;
    this->name = copy.name;
    this->weapon = copy.weapon;
}

HumanA& HumanA::operator=(const HumanA &copy)
{
    if (this == &copy)
        return (*this);
    this->name = copy.name;
    this->weapon = copy.weapon;
    return (*this);
}



void    HumanA::attack()
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}
