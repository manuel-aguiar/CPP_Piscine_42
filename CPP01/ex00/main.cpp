/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Zombie.h"

int main()
{
    Zombie *z = newZombie("yoyoyo");
    randomChump("brah");
    z->announce();
    Zombie stacker = *z; 
    randomChump("cenas");
    stacker.announce();
    stacker.namezzz("changing name");
    stacker.announce();
    delete z;
    return 0;
}