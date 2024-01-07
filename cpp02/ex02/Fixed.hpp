#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed(const int integer);
		Fixed(const float floater);
		Fixed( Fixed const & src );
		~Fixed();

		int 		getRawBits( void ) const;
		void 		setRawBits( int const raw );
        float       toFloat( void ) const;
        int         toInt( void ) const;

		Fixed &		operator++();
		Fixed &		operator--();
		Fixed 		operator++(int);
		Fixed 		operator--(int);

		Fixed &		operator=( Fixed const & rhs );
		Fixed 		operator+( Fixed const & rhs ) const;
		Fixed 		operator-( Fixed const & rhs ) const;
		Fixed 		operator*( Fixed const & rhs ) const;
		Fixed 		operator/( Fixed const & rhs ) const;
		bool 		operator>( Fixed const & rhs ) const;
		bool 		operator<( Fixed const & rhs ) const;
		bool 		operator>=( Fixed const & rhs ) const;
		bool 		operator<=( Fixed const & rhs ) const;
		bool 		operator==( Fixed const & rhs ) const;
		bool 		operator!=( Fixed const & rhs ) const;

        static Fixed &		min(Fixed & a, Fixed & b);
        static Fixed &		max(Fixed & a, Fixed & b);
        static Fixed const &	min(Fixed const & a, Fixed const & b);
        static Fixed const &	max(Fixed const & a, Fixed const & b);

	private:
		int	integer;
		static const int	bits = 8;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );
#endif
