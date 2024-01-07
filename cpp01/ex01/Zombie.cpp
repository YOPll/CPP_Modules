# include "Zombie.hpp"
void    Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void )
{
    std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << this->name << ": Has DIED" << std::endl;
}

void    Zombie::Nameit(std::string name)
{
    this->name = name;
}