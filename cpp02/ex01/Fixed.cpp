#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	integer = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(integer << this->bits);
}

Fixed::Fixed(const float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(floater * (1 << this->bits)));
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
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