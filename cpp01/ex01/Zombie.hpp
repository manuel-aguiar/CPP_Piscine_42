#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        Zombie(const Zombie &copy);
        Zombie &operator= (const Zombie &copy);
        
        void namezzz(const std::string &my_name);
        void announce (void);
        
    private:
        std::string name;
};


#endif