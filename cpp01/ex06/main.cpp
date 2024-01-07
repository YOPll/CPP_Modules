#include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl    obj;
     if (ac != 2)
        std::cout << "Usage : ./harlFilter (level)" << std::endl;
    else
        obj.complain(av[1]);
}
