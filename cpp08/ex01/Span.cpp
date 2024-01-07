#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	this->n = 0;
}

Span::Span( unsigned int n )
{
	this->n = n;
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->n = rhs.n;
		this->v = rhs.v;
	}
	return *this;
}

void	Span::addNumber( int n )
{
	if (this->v.size() < this->n)
		this->v.push_back(n);
	else
		throw std::out_of_range("Vector is full");
}

int		Span::shortestSpan()
{
	if (this->v.size() < 2)
		throw std::out_of_range("Vector is too small");
	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int		Span::longestSpan()
{
	if (this->v.size() < 2)
		throw std::out_of_range("Vector is too small");
	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}



/* ************************************************************************** */