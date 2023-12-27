#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed( const int i );
        Fixed( const float f );
        ~Fixed();
        Fixed( const Fixed& copy );
        Fixed&  operator= ( const Fixed& assign );
        
        std::ostream&   operator<< ( std::ostream& out );
        int                 getRawBits( void ) const;
        void                setRawBits( int const raw);
        float               toFloat( void );
        int                 toInt( void );
    
    private:
        int                 raw;
        static const int    frac = 8;
        
};




#endif