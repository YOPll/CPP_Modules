# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0)
        return (NULL);
    int i = 0;
    Zombie *Zombies = new Zombie[N];
    while (i < N)
    {
        Zombies[i].Nameit(name);
        i++;
    }
    return (Zombies);
}