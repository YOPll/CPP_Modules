#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap Hero("Hero");

	Hero.attack("Enemy");
	Hero.beRepaired(100);
	Hero.guardGate();
	Hero.takeDamage(150);
	Hero.attack("last Enemy");
	Hero.guardGate();

    return (0);
}