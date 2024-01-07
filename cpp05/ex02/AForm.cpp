#include "AForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): name("AForm"), signGrade(150), gradeExecute(150)
{
	this->is_s = false;
}

AForm::AForm( const std::string name, int signGrade, int gradeExecute) : name(name), signGrade(signGrade), gradeExecute(gradeExecute)
{
	if (signGrade < 1 || gradeExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150 || gradeExecute > 150)
		throw (AForm::GradeTooLowException());
	this->is_s = false;
}


AForm::AForm( const AForm & src ) : name(src.name), signGrade(src.signGrade), gradeExecute(src.gradeExecute)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	
	if ( this != &rhs )
	{
		this->is_s = rhs.is_s;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

const char * AForm::GradeTooHighException::what() const throw()
{
				return ("Grade is Too High!");
}

const char * AForm::GradeTooLowException::what() const throw()
{
				return ("Grade is Too Low!");
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  AForm::getName() const
{
	return (this->name);
}

int  AForm::getSign(void) const
{
	return (this->signGrade);
}

int AForm::getExecute() const
{
	return (this->gradeExecute);
}

bool AForm::sign(void) const
{
	return (this->is_s);
}

void AForm::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() <= this->signGrade)
		this->is_s = true;
	else
		throw (AForm::GradeTooLowException());
}



/* ************************************************************************** */

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "Form name: " << i.getName() << std::endl;
	if (i.sign() == true)
		o << "Form is signed" << std::endl;
	else
		o << "grade required to sign : " << std::endl;
	o << "Form signGrade: " << i.getSign() << std::endl << "grade required to execute :" << i.getExecute();
	return o;
}