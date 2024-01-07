#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap Hero("Saitama");
	FragTrap Enemy("Luffy");

	Hero.attack("Enemy");
	Hero.beRepaired(100);
	Hero.guardGate();
	Hero.takeDamage(150);
	Hero.attack("last Enemy");
	Hero.guardGate();

	Enemy.attack("Enemy");
	Enemy.beRepaired(10);
	Enemy.highFivesGuys();
	Enemy.takeDamage(150);
	Enemy.attack("last Enemy");
	Enemy.highFivesGuys();

    return (0);
}