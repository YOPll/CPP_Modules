#include "PhoneBook.hpp"

int     PhoneBook::validIndex(std::string choice)
{
    if (choice[0] >= '0' && choice[0] <= '7' && choice[1] == '\0')
        return (1);
    return (0);
}

int    PhoneBook::getIndex(void)
{
    return(this->i);
}

void    PhoneBook::initIndex(void)
{
    this->count = 0;
    this->i = 0;
}
void    PhoneBook::IncreaseIndex(void)
{
    if (this->i < 8)
        this->i++;
    if (this->i >= 8)
        this->i = 0;
    if (this->count < 8)
        this->count++;
}

void    PhoneBook::SEARCH(void)
{
    std::string choice;
    int j = PhoneBook::count;

    for (int x = 0; x < j ; x++)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(7) << "index " << std::right; 
        std::cout << "|" << std::setw(10);
        std::cout << " First Name " << std::right << "|";
        std::cout << std::setw(10) << " Last Name " << std::right;
        std::cout << "|" << std::setw(10);
        std::cout << " Nick Name" << std::right << "|"<< std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(7) << x;
        if (PhoneBook::Contact[x].getfirstName().length() > 10)
            std::cout << "|" << std::setw(12) <<  PhoneBook::Contact[x].getfirstName().substr(0,9) + ".";
        else
            std::cout << "|" << std::setw(12) <<  PhoneBook::Contact[x].getfirstName();
        if (PhoneBook::Contact[x].getlastName().length() > 10)
            std::cout << "|" << std::setw(11) <<  PhoneBook::Contact[x].getlastName().substr(0,9) + ".";
        else
            std::cout << "|" << std::setw(11) <<  PhoneBook::Contact[x].getlastName() ;
        if (PhoneBook::Contact[x].getnickName().length() > 10)
            std::cout << "|" << std::setw(10) <<  PhoneBook::Contact[x].getnickName().substr(0,9) + ".";
        else
            std::cout << "|" << std::setw(10) <<  PhoneBook::Contact[x].getnickName() << "|";
        std::cout << std::endl << "---------------------------------------------" << std::endl;
    }
    std::cout << "Insert Index: ";
    if (!std::getline(std::cin, choice))
        exit(1);
    if (validIndex(choice) == 1 && std::stoi(choice) < count)
    {
        std::cout << "Contact["<< choice << "] First Name: " << this->Contact[std::stoi(choice)].getfirstName() << std::endl;
        std::cout << "Contact["<< choice << "] Last Name: " << this->Contact[std::stoi(choice)].getlastName() << std::endl;
        std::cout << "Contact["<< choice << "] Nick Name: " << this->Contact[std::stoi(choice)].getnickName() << std::endl;
        std::cout << "Contact["<< choice << "] PhoneNumber: " << this->Contact[std::stoi(choice)].getphoneNumber() << std::endl;
        std::cout << "Contact["<< choice << "] DarkestSecret: " << this->Contact[std::stoi(choice)].getdarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid Index , Please Try AGAIN" << std::endl;
}
void    PhoneBook::ADD(void)
{
    std::string firstName,lastName,nickName,phoneNumber,darkestSecret;

    while (firstName.find_first_not_of("\t "))
    {
        std::cout << "insert firstName: ";
        if (!std::getline(std::cin, firstName))
            exit(1);
        if (firstName.empty())
        {
            std::cout << "firstName Can't Be empty" << std::endl;
            continue;
        }
    }
    this->Contact[i].setfirstName(firstName);
    while (lastName.find_first_not_of("\t "))
    {
        std::cout << "insert lastName: ";
        if (!std::getline(std::cin, lastName))
            exit(1);
        if (lastName.empty())
        {
            std::cout << "lastName Can't Be empty" << std::endl;
            continue;
        }
    }
    this->Contact[i].setlastName(lastName);
    while (nickName.find_first_not_of("\t "))
    {
        std::cout << "insert nickName: ";
        if (!std::getline(std::cin, nickName))
            exit(1);
        if (nickName.empty())
        {
            std::cout << "nickName Can't Be empty" << std::endl;
            continue;
        }
    }
    this->Contact[i].setnickName(nickName);
    while (phoneNumber.find_first_not_of("\t "))
    {
        std::cout << "insert phoneNumber: ";
        if (!std::getline(std::cin, phoneNumber))
            exit(1);
        if (phoneNumber.empty())
        {
            std::cout << "phoneNumber Can't Be empty" << std::endl;
            continue;
        }
    }
    this->Contact[i].setphoneNumber(phoneNumber);
    while (darkestSecret.find_first_not_of("\t "))
    {
        std::cout << "insert darkestSecret: ";
        if (!std::getline(std::cin, darkestSecret))
            exit(1);
        if (darkestSecret.empty())
        {
            std::cout << "darkestSecret Can't Be empty" << std::endl;
            continue;
        }
    }
    this->Contact[i].setdarkestSecret(darkestSecret);
    this->IncreaseIndex();
}

void    PhoneBook::Exit(void)
{
    std::cout << "Bye Bye :)" << std::endl;
    exit(0);
}

