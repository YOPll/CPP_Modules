#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat f("Boyka", 40);
		Form j("Wara9a", 40, 0);
		f.signForm(j);
		std::cout << j << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
//    try
//    {
//         Form form("form", 14, 15);
//         Bureaucrat burr("Bureau", 13);
        
//         form.beSigned(burr);
//         burr.signForm(form);
//         std::cout << form << std::endl; 
//    }
//    catch(const std::exception & e)
//    {
//         std::cerr << e.what() << std::endl;  
//    }
   return(0);
}