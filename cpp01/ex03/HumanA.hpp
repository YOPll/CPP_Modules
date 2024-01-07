#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
    public:
        HumanA(std::string const name , Weapon &weapon);
        void    attack(void);
    private:
        std::string name;
        Weapon      &weapon;
};

#endif