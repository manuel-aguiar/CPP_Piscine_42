/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "../incs/ClapTrap.hpp"

int main()
{
    ClapTrap potato ("potato");


    potato.attack("antonio");
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();
    potato.takeDamage(3000);
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();

    return 0;
}
