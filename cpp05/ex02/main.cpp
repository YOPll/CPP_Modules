#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
	{
		srand(time(NULL));
        Bureaucrat f("Boyka", 1);
		AForm *arr = new PresidentialPardonForm("Trump");
		f.signAForm(*arr);
		f.executeAForm(*arr);
		//std::cout << arr << std::endl;
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