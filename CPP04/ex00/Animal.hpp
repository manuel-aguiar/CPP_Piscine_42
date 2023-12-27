#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#include <string>

class Animal
{
    public:
        Animal();
        ~Animal();
        Animal(const Animal& copy);
        Animal& operator= (const Animal& assign);
    protected:
        std::string type;
};


#endif