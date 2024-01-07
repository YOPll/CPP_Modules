#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
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

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::string name;

	name = this->target + "_shrubbery";
	if (this->sign() == true)
	{
		if (executor.getGrade() <= this->getExecute())
		{
			std::ofstream file(name);
			if (file.is_open())
			{
				file << "                                              .         ;  \n";
    			file << "                 .              .              ;%     ;;   \n";
    			file << "                   ,           ,                :;%  %;   \n";
    			file << "                    :         ;                   :;%;'     .,   \n";
    			file << "           ,.        %;     %;            ;        %;'    ,;   \n";
    			file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'   \n";
    			file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'   \n";
    			file << "               ;%;      %;        ;%;        % ;%;  ,%;'   \n";
    			file << "                `%;.     ;%;     %;'         `;%%;.%;'   \n";
    			file << "                 `:;%.    ;%%. %@;        %; ;@%;%'   \n";
    			file << "                    `:%;.  :;bd%;          %;@%;'   \n";
    			file << "                      `@%:.  :;%.         ;@@%;'   \n";
    			file << "                        `@%.  `;@%.      ;@@%;         \n";
    			file << "                          `@%%. `@%%    ;@@%;         \n";
    			file << "                            ;@%. :@%%  %@@%;        \n";
    			file << "                              %@bd%%%bd%%:;         \n";
    			file << "                                #@%%%%%:;;         \n";
    			file << "                                %@@%%%::;         \n";
    			file << "                                %@@@%(o);  . '         \n";
    			file << "                                %@@@o%;:(.,'         \n";
    			file << "                            `.. %@@@o%::;         \n";
    			file << "                               `)@@@o%::;         \n";
    			file << "                                %@@(o)::;        \n";
    			file << "                               .%@@@@%::;         \n";
    			file << "                               ;%@@@@%::;.          \n";
    			file << "                              ;%@@@@%%:;;;.  \n";
    			file << "                          ...;%@@@@@%%:;;;;,..  \n";
			}
			file.close();
		}
		else
			throw ShrubberyCreationForm::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */