#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm: public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		void execute(const Bureaucrat& executor) const;

	private:
		std::string target;

};


#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */