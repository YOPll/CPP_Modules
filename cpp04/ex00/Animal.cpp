#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called" << std::endl;
	this->type = "Animal";
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound() const
{
	std::cout << "Default Animal Sound" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const
{
	return(this->type);
}


/* ************************************************************************** */