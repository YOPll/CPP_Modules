# include "Zombie.hpp"

int main()
{
    int i = 0;
    int size = 5;
    Zombie *zombies;
    zombies = zombieHorde(size, "YOPIIIIII");
    while (i < size)
    {
        zombies->announce();
        i++;
    }
    delete [] zombies;
}