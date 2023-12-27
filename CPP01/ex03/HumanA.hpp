#ifndef HUMANA_HPP

# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
    
    public:
    
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        HumanA(const HumanA& copy);
        HumanA& operator= (const HumanA& copy);
        
        void    attack();
    
    private:
        
        std::string     name;
        Weapon&         weapon;
        HumanA();
        
};






#endif