#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form( const std::string name, int signGrade, int gradeExecute);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string getName(void) const;
		bool sign(void) const;
		int getSign(void) const;
		int getExecute(void) const;
		void beSigned(const Bureaucrat& bur);

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
		bool				is_s;
		const int			signGrade;
		const int			gradeExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */