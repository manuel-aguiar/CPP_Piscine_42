/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"
# include <iostream>

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}


/*
int main()
{
    
    Weapon club = Weapon("stupid club");
    
    HumanA juau = HumanA("Juau", club);
    
    juau.attack();
    
    club.setType("spikesword");
    
    juau.attack();

    
    
    return 0;
}*/