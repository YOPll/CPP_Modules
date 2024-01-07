# include "Zombie.hpp"

int main()
{
Zombie *Zombie1 = newZombie("Zomboy1");
Zombie1->announce();
randomChump("Zomboy2");
randomChump("Zomboy3");
delete (Zombie1);
}
