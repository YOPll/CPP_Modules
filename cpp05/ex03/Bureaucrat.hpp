#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm ;
class Bureaucrat
{
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		const std::string getName() const;
		int	getGrade() const;

		void	increment(void);
		void	decrement(void);

		void	signAForm(AForm & AForm);
		void	executeAForm(AForm const & form);

	class GradeTooHighException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char *what() const throw();
	};

	private:
		const std::string	name;
		int					grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );


#endif /* ****************************************************** BUREAUCRAT_H */