#include "Form.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): name("Form"), signGrade(150), gradeExecute(150)
{
	this->is_s = false;
}

Form::Form( const std::string name, int signGrade, int gradeExecute) : name(name), signGrade(signGrade), gradeExecute(gradeExecute)
{
	if (signGrade < 1 || gradeExecute < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150 || gradeExecute > 150)
		throw (Form::GradeTooLowException());
	this->is_s = false;
}


Form::Form( const Form & src ) : name(src.name), signGrade(src.signGrade), gradeExecute(src.gradeExecute)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
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

const char * Form::GradeTooHighException::what() const throw()
{
				return ("Grade is Too High!");
}

const char * Form::GradeTooLowException::what() const throw()
{
				return ("Grade is Too Low!");
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  Form::getName() const
{
	return (this->name);
}

int  Form::getSign(void) const
{
	return (this->signGrade);
}

int Form::getExecute() const
{
	return (this->gradeExecute);
}

bool Form::sign(void) const
{
	return (this->is_s);
}

void Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() <= this->signGrade)
		this->is_s = true;
	else
		throw (Form::GradeTooLowException());
}



/* ************************************************************************** */

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name: " << i.getName() << std::endl;
	if (i.sign() == true)
		o << "Form is signed" << std::endl;
	else
		o << "grade required to sign : " << std::endl;
	o << "Form signGrade: " << i.getSign() << std::endl << "grade required to execute :" << i.getExecute();
	return o;
}