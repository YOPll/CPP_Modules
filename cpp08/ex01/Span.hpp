#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{

	public:

		Span();
		Span( Span const & src );
		~Span();

		Span( unsigned int n );
		void	addNumber( int n );
		int		shortestSpan();
		int		longestSpan();
		void	addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );

		Span &		operator=( Span const & rhs );

	private:
		
		unsigned int		n;
		std::vector<int>	v;

};


#endif /* ************************************************************ SPAN_H */