#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Unnamed ScavTrap Constructor called" << std::endl;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "Named ScavTrap - " << name << " - Constructor called" << std::endl;
    hitpoints = SCAV_START_HP;
    energypoints = SCAV_START_EP;
    attackdamage = SCAV_START_ATTACK;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    if (this == &copy)
	 return ;
    this->name = copy.name;
    this->hitpoints = copy.hitpoints;
    this->energypoints = copy.energypoints;
    this->attackdamage = copy.attackdamage;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& assign)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this == &assign)
	 return (*this);
    this->name = assign.name;
    this->hitpoints = assign.hitpoints;
    this->energypoints = assign.energypoints;
    this->attackdamage = assign.attackdamage;
    return (*this);
}


void    ScavTrap::guardGate()
{
    this->gatekeeping = true;
    std::cout << "ScavTrap " << this->name << " is in Gate Keeper mode." << std::endl;
}

