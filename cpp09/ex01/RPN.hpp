#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <sstream>



class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		void				notate(char **av);

	private:
		std::stack<int>		_stack;

};

#endif /* ************************************************************* RPN_H */