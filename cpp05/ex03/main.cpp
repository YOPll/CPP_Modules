#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("YOPI", 1);
		Intern  leetintern;
		AForm *form;

		form = leetintern.makeForm("presidential pardon", "JOJO");
		if (form)
		{
			a.signAForm(*form);
			a.executeAForm(*form);
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}