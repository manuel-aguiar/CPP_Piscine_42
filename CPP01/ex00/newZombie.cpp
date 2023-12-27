#include "Zombie.h"
#include <new>

Zombie *newZombie (std::string name)
{
    Zombie      *z;
    
    z = new (std::nothrow) Zombie;
    if (!z)
        return (NULL);
    z->namezzz(name);
    return (z);
}