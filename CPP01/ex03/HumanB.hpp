#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
    
    public:
    
        HumanB(const std::string& name);
        ~HumanB();
        HumanB(const HumanB& copy);
        HumanB& operator= (const HumanB& copy);
        
        void    attack();
        void    setWeapon(Weapon& weapon);
    
    private:
        
        std::string     name;
        Weapon*         weapon;
        HumanB();
        
};






#endif