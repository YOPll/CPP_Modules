#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# define MAX_UNSIGNED_INT 4294967295

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();
		FragTrap &		operator=( FragTrap const & rhs );

		void attack(const std::string& target);
        void highFivesGuys(void);

};

#endif 