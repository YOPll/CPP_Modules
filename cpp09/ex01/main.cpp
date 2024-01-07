# include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Error: Wrong number of arguments" << std::endl;
    else
    {
        RPN rpn;
        rpn.notate(av);
    }
    return 0;
}