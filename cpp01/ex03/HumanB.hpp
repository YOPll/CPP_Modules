#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon &WeaponRef);
        void    attack(void);
    private:
        Weapon *weapon;
        std::string name;
};

#endif