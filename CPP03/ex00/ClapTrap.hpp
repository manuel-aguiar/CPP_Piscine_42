#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define START_HP 10
#define START_EP 10
#define START_ATTACK 0
#define START_NAME "Unnamed"

class ClapTrap
{
    public:
        ClapTrap(const std::string& name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator= (const ClapTrap& assign);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    my_stats( void );
    private:
        ClapTrap();
        std::string name;
        unsigned int hitpoints;
        unsigned int energypoints;
        unsigned int attackdamage;
};




#endif