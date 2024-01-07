#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->name = "Default_name";
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
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

void	FragTrap::attack(const std::string &target)
{
	if (!this->Hit_points)
	{
		std::cout << "FragTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
	if (this->Energy_points > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", Causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
	else
		std::cout << "FragTrap " << this->name << " No energy left" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
	if (!this->Hit_points)
	{
		std::cout << "FragTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
    std::cout << "FragTrap " << this->name << " has requested high fives !" << std::endl;
}


/* ************************************************************************** */