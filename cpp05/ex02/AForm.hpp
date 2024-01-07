#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm( const std::string name, int signGrade, int gradeExecute);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string getName(void) const;
		bool sign(void) const;
		int getSign(void) const;
		int getExecute(void) const;
		void beSigned(const Bureaucrat& bur);
		virtual void execute(const Bureaucrat& executor) const = 0;

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

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */