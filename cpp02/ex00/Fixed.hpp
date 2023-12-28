#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& copy);
        Fixed&  operator= (const Fixed& assign);

        int     getRawBits( void ) const;
        void    setRawBits( int const set_raw);

    private:
        int                 raw;
        static const int    frac = 8;

};




#endif
