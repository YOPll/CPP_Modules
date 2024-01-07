# include "ScalarConverter.hpp"


int main(int ac, char **av)
{
   switch(ac)
   {
         case 1:
              std::cout << "No arguments" << std::endl;
              return 1;
         case 2:
               //  ScalarConverter scalar;
               ScalarConverter::convert(av[1]);
                break;
         default:
              std::cout << "Too many arguments" << std::endl;
              break;
   }
    return (0);
}
