/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Zombie.h"

int main()
{
    int total = 5;
    Zombie *horde;
    
    horde = zombieHorde(total, "brah");
    if (!horde)
        return (1);
    for (int i = 0; i < total; i++)
        horde[i].announce();
    
    delete[] horde;
    return (0);
}