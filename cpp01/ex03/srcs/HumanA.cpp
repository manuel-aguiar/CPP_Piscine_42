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
}

HumanA& HumanA::operator=(const HumanA &assign)
{
    if (this == &assign)
        return (*this);
    this->name = assign.name;
    this->weapon = assign.weapon;
    return (*this);
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}
