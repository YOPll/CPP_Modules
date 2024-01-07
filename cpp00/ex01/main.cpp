#include "PhoneBook.hpp"

int	main()
{
    std::string line;
    PhoneBook phone;
    phone.initIndex();
    std::cout << "Welcome To YOUR PHONEBOOK" << std::endl;
    std::cout << "To Us you Can Type (ADD, SEARCH, EXIT)" << std::endl;

    while (1)
    {
        std::cout << "$ ";
        if (!std::getline(std::cin, line))
            exit(1);
        else if (line.empty())
            continue;
        else if (line.compare("EXIT") == 0)
            phone.Exit();
        else if (line.compare("ADD") == 0)
            phone.ADD();
        else if (line.compare("SEARCH") == 0)
            phone.SEARCH();
        else
            std::cout << " >> Command Not Found" << std::endl;

    }
}