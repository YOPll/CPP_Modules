#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << " I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = -1;
    std::string lvl[4] = {"DEBUG", "INFO" , "WARNING", "ERROR"};
    Harl    obj;
    void (Harl::*p[4])(void);
    p[0] = &Harl::debug;
    p[1] = &Harl::info;
    p[2] = &Harl::warning;
    p[3] = &Harl::error;

    while (++i < 4)
        if (level == lvl[i])
            break;
    switch (i)
    {
        case 0:
            obj.debug();
        case 1:
            obj.info();
        case 2:
            obj.warning();
        case 3:
            obj.error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}