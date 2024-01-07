#include "ClapTrap.hpp"

int main()
{
	ClapTrap	hero("Hero");
	ClapTrap	no_one("anonymous");

	hero.setAttackdamage(4);
	hero.attack("anonymous");
    no_one.takeDamage(4);
    no_one.setAttackdamage(7);
	no_one.attack("Hero");
    hero.takeDamage(7);
	hero.beRepaired(100);
	//hero.takeDamage(99999);
	//no_one.attack("last enemy");
	no_one.beRepaired(99);
    return (0);
}