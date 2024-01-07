#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = "Default_name";
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->Hit_points = rhs.Hit_points;
		this->Attack_damage = rhs.Attack_damage;
		this->Energy_points = rhs.Energy_points;
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->Hit_points)
	{
		std::cout << "ScavTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
	if (this->Energy_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", Causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
	else
		std::cout << "ScavTrap " << this->name << " No energy left" << std::endl;
}

void    ScavTrap::guardGate(void)
{
	if (!this->Hit_points)
	{
		std::cout << "ScavTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}


/* ************************************************************************** */