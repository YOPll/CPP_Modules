#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = "Default_name";
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
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

void	ClapTrap::attack(const std::string &target)
{
	if (!this->Hit_points)
	{
		std::cout << "ClapTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
	if (this->Energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", Causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->name << " No energy left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->Hit_points)
	{
		std::cout << "ClapTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " took -" << amount << " of damage!"<< std::endl;
	if (amount > this->Hit_points)
		this->Hit_points = 0;
	else
		this->Hit_points -=amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->Hit_points)
	{
		std::cout << "ClapTrap " << this->name << " He's Dead" << std::endl;
		return ;
	}
	if (this->Energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " Healed " << amount << " points of damage!" << std::endl;
		if (amount + this->Hit_points > MAX_UNSIGNED_INT)
			this->Hit_points = MAX_UNSIGNED_INT;
		else
			this->Hit_points += amount;
		this->Energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->name << " No energy left" << std::endl;
		
}

void	ClapTrap::setAttackdamage(int const Attackdamage)
{
	this->Attack_damage = Attackdamage;
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->Hit_points);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->Energy_points);
}



/* ************************************************************************** */