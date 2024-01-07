#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}



RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->_stack = rhs._stack;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::notate(char **av)
{
	std::string token;
	std::string str = av[1];
	if (str.find_first_not_of(" \r\n\f\t\v") == std::string::npos)
	{
		std::cout << "Error: empty arg " << std::endl;
		exit (1);
	}

	std::istringstream ss(av[1]);

	int hardcode = 0;
	while (ss>>token)
	{
		hardcode = 0;
		if (token.front() == '-' && token.back() != '-' && std::isdigit(token.back())) {
			hardcode = atoi(token.c_str());
			_stack.push(hardcode);
			continue;
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error: Not enough operands" << std::endl;
				exit (1);
			}
			int n2 = _stack.top();
			_stack.pop();
			int n1 = _stack.top();
			_stack.pop();
			int res = 0;
			if (token == "+")
				res = n1 + n2;
			else if (token == "-")
				res = n1 - n2;
			else if (token == "*")
				res = n1 * n2;
			else if (token == "/")
			{
				if (n2 == 0)
				{
					std::cout << "Error: Division by zero" << std::endl;
					exit (1);
				}
				res = n1 / n2;
			}
			_stack.push(res);
		}
		else
		{
			for(int i=0; token[i] !='\0'; i++)
			{
        		if(!isdigit(token[i]))
				{
            		std::cout << "Error: bad input." << std::endl;
            		exit(1);
        		}
    		}
			_stack.push(std::atoi(token.c_str()));
		}
	}
	if (_stack.size() > 1)
	{
		std::cout << "Error: Too many operands" << std::endl;
		exit (1);
	}
	std::cout << _stack.top() << std::endl;
}


/* ************************************************************************** */