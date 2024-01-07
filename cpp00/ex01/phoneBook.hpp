#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# include <iostream>
# include <iomanip>
# include <string>


class PhoneBook
{
    public:
            void    SEARCH(void);
            void    IncreaseIndex(void);
            void    ADD(void);
            void    Exit(void);
            void    initIndex(void);
            int     validIndex(std::string choice);
            int     getIndex(void);
    private:
            Contact Contact[8];
            int i;
            int count;
};

#endif
