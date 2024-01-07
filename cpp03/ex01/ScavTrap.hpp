#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define MAX_UNSIGNED_INT 4294967295

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();
		ScavTrap &		operator=( ScavTrap const & rhs );

		void attack(const std::string& target);
        void guardGate();

};

#endif 