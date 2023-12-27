#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define CLAP_START_NAME "Unnamed"
#define CLAP_START_HP 10
#define CLAP_START_EP 10
#define CLAP_START_ATTACK 0

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator= (const ClapTrap& assign);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    my_stats( void );
    protected:
        std::string name;
        unsigned int hitpoints;
        unsigned int energypoints;
        unsigned int attackdamage;
};




#endif