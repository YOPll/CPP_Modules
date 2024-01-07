#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    else if (!allPositiveNumbers(ac, av))
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    int i = 1;
    std::cout << "Before: ";
    if (ac > 6)
    {
        while (i < 5)
        {
            std::cout << av[i] << " ";
            i++;
        }
        std::cout << "[..]";
    }
    else
    {
        while (i < ac)
        {
            std::cout << av[i] << " ";
            i++;
        }
    }
    std::cout << std::endl;
    sort_vector(ac, av);
    sort_deque(ac, av);

    return 0;
}