#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Unnamed ClapTrap Constructor called" << std::endl;
    this->name = CLAP_START_NAME;
    this->hitpoints = CLAP_START_HP;
    this->energypoints = CLAP_START_EP;
    this->attackdamage = CLAP_START_ATTACK;
}

ClapTrap::ClapTrap(const std::string& name) : name(name)
{
    std::cout << "Named ClapTrap - " << name << " - Constructor called" << std::endl;
    this->hitpoints = CLAP_START_HP;
    this->energypoints = CLAP_START_EP;
    this->attackdamage = CLAP_START_ATTACK;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    if (this == &copy)
        return ;
    this->name = copy.name;
    this->hitpoints = copy.hitpoints;
    this->energypoints = copy.energypoints;
    this->attackdamage = copy.attackdamage;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& assign)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &assign)
        return (*this);
    this->name = assign.name;
    this->hitpoints = assign.hitpoints;
    this->energypoints = assign.energypoints;
    this->attackdamage = assign.attackdamage;
    return (*this);
}


void    ClapTrap::attack(const std::string& target)
{
    std::cout << this->name << " wants to attack " << target << ", checking energy..." << std::endl;
    if (this->hitpoints <= 0)
    {
        std::cout << this->name << " is dead, can't attack" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, attack failed" << std::endl;
    }
    else
    {
        this->energypoints--;
        std::cout << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " is taking damage, checking stats..." << std::endl;
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, attack failed" << std::endl;
    }
    else
    {
        this->hitpoints = (this->hitpoints - amount) * (this->hitpoints > amount);
        std::cout << this->name << " takes " << amount << " of damage! " << std::endl;
    }
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is dead, no HP left" << std::endl;
        return ;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->name << " wants to repare, checking stats..." << std::endl;
    if (this->hitpoints == 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return ;
    }
    if (this->energypoints == 0)
    {
        std::cout << this->name << " has no energy left, repair failed" << std::endl;
    }
    else
    {
        this->energypoints--;
        this->hitpoints += amount;
        std::cout << this->name << " repairs " << amount << " points! " << std::endl;
    }
}

void    ClapTrap::my_stats( void )
{
    std::cout << std::endl;
    std::cout << "Stats: " << this->name << std::endl;
    std::cout << "   HP: " << this->hitpoints << std::endl;
    std::cout << "   EP: " << this->energypoints << std::endl;
    std::cout << "   Attack Strength: " << this->attackdamage << std::endl;
    std::cout << std::endl;
}
