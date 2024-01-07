#include "Bureaucrat.hpp"

int main()
{
   try
    {
        Bureaucrat first;
        Bureaucrat second("s2", 100);
        Bureaucrat third("s3", 151);
        Bureaucrat forth(third);    
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat first;

        first.decrement();
        std::cout << first.getGrade() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    Bureaucrat obj("YOPI", 150);
    
    Bureaucrat test(obj);

    std::cout << test.getName() << std::endl ; 
    std::cout << test.getGrade() << std::endl ; 
    return (0);
}