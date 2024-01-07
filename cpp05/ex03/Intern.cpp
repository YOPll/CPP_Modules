#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (form == forms[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << forms[0] << std::endl;
		return new ShrubberyCreationForm(target);
		break;
	case 1:
		std::cout << "Intern creates " << forms[1] << std::endl;
		return new RobotomyRequestForm(target);
		break;
	case 2:
		std::cout << "Intern creates " << forms[2] << std::endl;
		return new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "Intern can't create " << form << std::endl;
		break;
	}
	return NULL;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */