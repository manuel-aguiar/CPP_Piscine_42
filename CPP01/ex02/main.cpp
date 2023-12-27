/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

int main()
{
    std::string     brain = "HI THIS IS BRAIN";
    std::string*    stringPTR = &brain;
    std::string&    stringREF = brain;
    
    std::cout << "Address of string object:                        " << &brain << std::endl;
    std::cout << "Address held by pointer to string:               " << stringPTR << std::endl;
    std::cout << "Address held by reference to string:             " << &stringREF << std::endl;

    std::cout << "Value of string object:                          " << brain << std::endl;
    std::cout << "Value at address held by pointer to string:      " << *stringPTR << std::endl;
    std::cout << "Value at address held by reference to string:    " << stringREF << std::endl;

    return 0;
}