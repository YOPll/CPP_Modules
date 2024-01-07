#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	integer = 0;
}

Fixed::Fixed(const int integer)
{
	this->setRawBits(integer << this->bits);
}

Fixed::Fixed(const float floater)
{
	this->setRawBits(roundf(floater * (1 << this->bits)));
}

Fixed::Fixed( const Fixed & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
		this->integer = rhs.getRawBits();
	return (*this);
}

int 		Fixed::getRawBits( void ) const
{
	return (this->integer);
}

void Fixed::setRawBits( int const raw )
{
	this->integer = raw;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << "Value = " << i.toFloat();
	return o;
}

float       Fixed::toFloat( void ) const
{
    return ((float)this->integer / (float)(1 << this->bits));
}

int         Fixed::toInt( void ) const
{
    return (this->integer >> this->bits);
}

// --------------------------------------------

Fixed 		Fixed::operator+( Fixed const & rhs ) const
{
    /* It's creating a new Fixed object, and initializing it with the value of the current object. */
    Fixed tmp(*this);
    tmp.setRawBits(this->integer + rhs.getRawBits());
    return (tmp);
}

Fixed 		Fixed::operator-( Fixed const & rhs ) const
{
    Fixed tmp(*this);
    tmp.setRawBits(this->integer - rhs.getRawBits());
    return (tmp);
}

Fixed 		Fixed::operator*( Fixed const & rhs ) const
{
    Fixed tmp(*this);
    tmp.setRawBits(this->integer * rhs.getRawBits() >> this->bits);
    return (tmp);
}

Fixed 		Fixed::operator/( Fixed const & rhs ) const
{
    Fixed tmp(*this);
    tmp.setRawBits(roundf(((float)this->integer / (float)rhs.getRawBits()) * (1 << this->bits)));
    // tmp.setRawBits((this->integer / rhs.getRawBits()));
    return (tmp);
}

bool		Fixed::operator>( Fixed const & rhs ) const
{
    return (this->integer > rhs.getRawBits());
}

bool		Fixed::operator<( Fixed const & rhs ) const
{
    return (this->integer < rhs.getRawBits());
}

bool		Fixed::operator>=( Fixed const & rhs ) const
{
    return (this->integer >= rhs.getRawBits() || *this == rhs);
}

bool		Fixed::operator<=( Fixed const & rhs ) const
{
    return (this->integer <= rhs.getRawBits()  || *this == rhs);
}

bool		Fixed::operator==( Fixed const & rhs ) const
{
    return (this->integer == rhs.getRawBits());
}

bool		Fixed::operator!=( Fixed const & rhs ) const
{
    return (!(*this == rhs));
}


const Fixed &		Fixed::min(Fixed const & a, Fixed const & b)
{
    return (a < b ? a : b);
}

const Fixed &		Fixed::max(Fixed const & a, Fixed const & b)
{
    return (a > b ? a : b);
}

Fixed &		Fixed::min(Fixed & a, Fixed & b)
{
    return (a < b ? a : b);
}

Fixed &		Fixed::max(Fixed & a, Fixed & b)
{
    return (a > b ? a : b);
}


Fixed &		Fixed::operator++()
{
    ++(this->integer);
    return (*this);
}

Fixed		Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

Fixed &		Fixed::operator--()
{
    --(this->integer);
    return (*this);
}

Fixed		Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}