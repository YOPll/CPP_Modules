#include "HumanB.hpp"


void    HumanB::attack(void)
{
    if (!this->weapon)
        std::cout << this->name << " No Weapon yet :( "<< std::endl;
    else
        std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &Weapon)
{
    this->weapon = &Weapon;
}

HumanB::HumanB(std::string name):weapon(NULL) , name(name) 
{}