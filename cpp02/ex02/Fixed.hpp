#ifndef FIXED_HPP

# define FIXED_HPP

/*

Representing fixed point numbers of type <32, 8>, meaning:
	32 total bits
	8 rightmost bits are used for the fraction

	member raw_bits: all the bits represented as is it was an integer
	member fraction_bits: number of rightmost bits used for the fraction part:
		23 bits for the integer part
		8 bits for the floating part (static const initialized imeddiatelly)
		1 bit for sign of the number

Converting an int to fixed point of fraction 8 means the loss of 8 bits to
represent a full int
Therefore fixed_point FIXED_INT_MAX = INT_MAX >> 8
					  FIXED_INT_MIN = INT_MIN >> 8

*/

# include <iostream>
# include <cmath>
# include <limits.h>

# define FRAC_BITS 8

# define FIXED_INT_MAX (INT_MAX >> FRAC_BITS)
# define FIXED_INT_MIN (INT_MIN >> FRAC_BITS)

class Fixed
{
    public:
        Fixed();
        Fixed( const int i );
        Fixed( const float f );

        ~Fixed();

        Fixed( const Fixed& copy );
        Fixed&  operator= ( const Fixed& assign );

        int                 getRawBits( void ) const;
        void                setRawBits( int const raw);
        float               toFloat( void ) const;
        int                 toInt( void ) const;

		// comparison operator overloads
		bool	operator> (const Fixed& other);
		bool	operator< (const Fixed& other);
		bool	operator>= (const Fixed& other);
		bool	operator<= (const Fixed& other);
		bool	operator== (const Fixed& other);
		bool	operator!= (const Fixed& other);

		// arithmatic operator overloads

		Fixed	operator+ (const Fixed& other);
		Fixed	operator- (const Fixed& other);
		Fixed	operator* (const Fixed& other);
		Fixed	operator/ (const Fixed& other);


		// increment operator overloads

		Fixed&	operator++(void);


		Fixed&	operator--(void);

		// public member functions

		static	Fixed&	min(Fixed& first, Fixed& second);
		static	const Fixed&	min(const Fixed& first, const Fixed& second);
		static	Fixed&	max(Fixed& first, Fixed& second);
		static	const Fixed&	max(const Fixed& first, const Fixed& second);

    private:
        int                 raw_bits;
        static const int    frac_bits = FRAC_BITS;

};

/*
	Placing the overload inside the class requires the use of the friend keywork which is forbidden
	It is the std::ostream class that is being overloaded with a new prototype
		polimorphism guarantees that when overloading with our class's prototype, compilation
		will make use of the overload we created on OSTREAM for our own class

	In reality we are providing a new operator overload to std::ostream to be able to print our class

	friend keyword inside our class would allow std::ostream to access our class via this function
		(forbidden for exercise purposes)


	this is called a "non-member function overload", same as std::string can << to std::cout
		there is an overload of std::cout that takes a std::string as input and allows it to print
		to cout

	std::cout has multiple overloads for the various classes
		the correct overload is decided at compile time taking into account the input parameters
		that are given to the operator
		- compile-time polymorphism

*/

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif
