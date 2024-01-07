#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:
        Weapon(std::string type) : type(type) {};
        std::string const &getType(void) const;
        void    setType(std::string type);
    private:
        std::string type;
};

#endif 
