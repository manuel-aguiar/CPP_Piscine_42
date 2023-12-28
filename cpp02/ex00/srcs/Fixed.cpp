#include "Fixed.hpp"

Fixed::Fixed( void ) : raw_bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : raw_bits(copy.raw_bits)
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

    raw_bits = assign.raw_bits;
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (this->raw_bits);
}

void     Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called" << std::endl;
    raw_bits = raw;
}
