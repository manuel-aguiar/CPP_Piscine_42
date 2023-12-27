/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

void capitalize_str(std::string &str)
{
    std::string::size_type  i;
    std::string::size_type  len;
    
    len = str.size();
    for (i = 0; i < len; i++)
        str[i] = std::toupper(str[i]);
}

int main(int ac, char **av)
{
    std::string loud;
    
    for (int i = 1; i < ac; i++)
    {
        loud = av[i];
        capitalize_str(loud);
        std::cout << loud;
    }
    std::cout << std::endl;
    return 0;
}
