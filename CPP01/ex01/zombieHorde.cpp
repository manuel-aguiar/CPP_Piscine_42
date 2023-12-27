#include "Zombie.h"
#include <new>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde;
    int     i;
    
    horde = new (std::nothrow) Zombie[N];
    if (!horde)
        return (NULL);
    
    for (i = 0; i < N; i++)
        horde[i].namezzz(name);
        
    return (horde);
}