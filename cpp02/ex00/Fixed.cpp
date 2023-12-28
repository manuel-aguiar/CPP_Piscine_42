#include "Fixed.hpp"

Fixed::Fixed( void ) : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : raw(copy.raw)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this == &copy)
    {
        std::cout << "Copy constructor: this == copy" << std::endl;
        return ;
    }
}

Fixed& Fixed::operator= (const Fixed& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
        std::cout << "Copy assignment: this == copy" << std::endl;
        return (*this);
    }

    raw = assign.raw;
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (this->raw);
}

void     Fixed::setRawBits( int const set_raw )
{
    std::cout << "setRawBits function called" << std::endl;
    raw = set_raw;
}
