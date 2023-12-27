#include "Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->raw = 0;
}

Fixed::Fixed( const int i )
{
    std::cout << "Int constructor called" << std::endl;
    this->raw = i << 8;
}

Fixed::Fixed( const float f )
{
    std::cout << "Float constructor called" << std::endl;
    this->raw = 0;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this == &copy)
    {
        std::cout << "Copy constructor: this == copy" << std::endl;
        return ;
    }
        
    this->raw = copy.getRawBits();
    
}

Fixed& Fixed::operator= (const Fixed& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &assign)
    {
        std::cout << "Copy assignment: this == copy" << std::endl;
        return (*this);
    }
        
    this->raw = assign.getRawBits();
    return (*this);
}

std::ostream&   Fixed::operator<< ( std::ostream& out )
{
    float   f;
    
    f = 123.0f;
    
    out << f;
    
    return (out);
}

float   Fixed::toFloat( void )
{
    float f = 123.0f;
    return (f);
}

int     Fixed::toInt( void )
{
    return (this->raw >> 8);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (this->raw);
}

void     Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called" << std::endl;
    this->raw = raw;
    
}
