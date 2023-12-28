#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


#define SCAV_START_NAME "Unnamed"
#define SCAV_START_HP 100
#define SCAV_START_EP 50
#define SCAV_START_ATTACK 20

class ScavTrap : public ClapTrap
{
    public:
	 ScavTrap();
	 ScavTrap(const std::string& name);
	 ~ScavTrap();
	 ScavTrap(const ScavTrap& copy);
	 ScavTrap& operator= (const ScavTrap& assign);
	 void    guardGate();
    private:
	 bool    gatekeeping;
};




#endif
