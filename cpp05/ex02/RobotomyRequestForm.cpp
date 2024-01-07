#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm("RobotomyRequestForm", 72, 45)
{
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->target = rhs.target;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->sign() == true)
	{
		if (executor.getGrade() <= this->getExecute())
		{
			std::cout << "Drilling noises !" << std::endl;
			if (rand() % 2)
				std::cout << this->target << " has been robotomized successfully." << std::endl;
			else
				std::cout << this->target << " has been robotomized unsuccessfully." << std::endl;
		}
		else
			throw RobotomyRequestForm::GradeTooLowException();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */