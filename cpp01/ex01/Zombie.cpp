#include "Zombie.hpp"

Zombie::Zombie()
{
    
}

Zombie::~Zombie()
{
    std::cout << this->name << ": deadzzz" << std::endl;
}

Zombie::Zombie(const Zombie &copy)
{
    if (this == &copy)
        return ;
    this->name = copy.name;
}

Zombie  &Zombie::operator=(const Zombie &copy)
{
    if (this == &copy)
        return (*this);
    this->name = copy.name;
    return (*this);
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::namezzz(const std::string &my_name)
{
    this->name = my_name;
}
